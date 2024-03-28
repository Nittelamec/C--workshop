#include "colony.hh"

#include <iostream>
#include <memory>

#include "ant.hh"
#include "nurturer.hh"
#include "provider.hh"
#include "queen.hh"
#include "worker.hh"

Colony::Colony(uint32_t passport)
    : passport_pheromone_(passport)
    , workers_()
{}

void Colony::manageQueen()
{
    if (queen_ == nullptr)
        throw std::runtime_error("Cannot manage a colony without a Queen.");
    // check if the queen should lose health points
    if (queen_->food_level_ < 0)
        queen_->hp_ -= 1;
    if (queen_->hp_ <= 0)
    {
        queen_ = nullptr;
        throw std::runtime_error("The Queen died.");
    }
    // Append to workers_ all the new workers contained in the queen's
    // eggs_queue_
    while (!queen_->eggs_queue_.empty())
    {
        //! we insert eggs that were laid by the queen
        workers_.emplace_back(queen_->eggs_queue_.front());
        queen_->eggs_queue_.pop();
    }
}

void Colony::removeDeadWorkers()
{
    auto dead_count = std::erase_if(
        workers_, [](const std::shared_ptr<Worker> w) { return w->hp_ <= 0; });
    if (dead_count > 0)
    {
        std::cout << dead_count << " workers_ died.\n";
        // each dead worker decrease the cleanliness of the colony
        cleanliness -= 0.5 * dead_count;
    }
}

// this method can be considered as one round of management
void Colony::manageAnts()
{
    // We first manage the queen
    manageQueen();
    // We remove all dead workers contained in workers_
    removeDeadWorkers();
    std::cout << "-- THERE IS " << workers_.size() << " WORKERS --\n";
    // We iterate over all workers
    for (auto worker : workers_)
    {
        if (worker->stage_ == DevelopmentStage::ADULT)
        {
            /*
             * Because work() is a virtual method, dynamic dispatch will be
             * used. Which means that the overridden work method of the true
             * type (either Nurturer or Provider) will actually be called
             * instead of Worker::work().
             */
            worker->work();
        }
        else
        {
            /*
             * We increment their food_level_ as if it is a ticking time,
             * EXCEPT for the larvae, as they are fed by nurturers.
             */
            if (worker->stage_ != DevelopmentStage::LARVA)
                worker->food_level_ += 1;
            if (worker->food_level_ >= 4.0)
            {
                unsigned int cast_dev_stage =
                    static_cast<unsigned int>(worker->get_stage());
                worker->stage_ =
                    static_cast<DevelopmentStage>(cast_dev_stage + 1);
                worker->food_level_ = 0;
                /* FIXME : Make the worker change stage_ and reset their
                 * food_level_ to 0. HINT : This can take only 2/3 lines if you
                 * use a certain C++ cast instead of a switch.
                 */
            }
        }
    }
    queen_->food_level_ -= 0.2;
}

// FIXME : Implements addAnt() static method.
bool Colony::addAnt(const Ant& ant, std::shared_ptr<Colony> colony)
{
    const Provider* cast_provider = dynamic_cast<const Provider*>(&ant);
    const Queen* cast_queen = dynamic_cast<const Queen*>(&ant);
    const Nurturer* cast_nurturer = dynamic_cast<const Nurturer*>(&ant);
    if (cast_provider == nullptr && cast_queen == nullptr
        && cast_nurturer == nullptr)
        return false;
    else
    {
        if (cast_queen != nullptr)
        {
            if (colony->queen_ != nullptr)
                return false; // rajouter test
            if (cast_queen->get_stage() != DevelopmentStage::ADULT)
                return false;
            colony->queen_ = std::make_unique<Queen>(*cast_queen);
        }
        else if (cast_nurturer != nullptr)
            colony->workers_.push_back(
                std::make_shared<Nurturer>(*cast_nurturer));
        else
            colony->workers_.push_back(
                std::make_shared<Provider>(*cast_provider));
        return true;
    }
}
