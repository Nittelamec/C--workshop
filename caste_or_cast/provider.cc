#include "provider.hh"

#include <iostream>

#include "ant.hh"
#include "nurturer.hh"

void Provider::harvestFood()
{
    std::cout << "Harvested " << std::defaultfloat << luck_ << " food.\n";
    food_stock_ += luck_;

    int whole_part = static_cast<int>(luck_);
    float cast_float = static_cast<float>(whole_part);
    float decimal_part = luck_ - cast_float;
    food_level_ -= decimal_part / 2.f;
}

void Provider::work()
{
    if (this->get_stage() != DevelopmentStage::ADULT)
        return;

    int whole_part_stock = static_cast<int>(food_stock_);
    float cast_float = static_cast<float>(whole_part_stock);
    float decimal_part = food_stock_ - cast_float;

    food_level_ += decimal_part;
    food_stock_ = cast_float;

    harvestFood();
    Worker::work();
}

void Provider::transferFood(Nurturer& nurturer)
{
    if (food_stock_ < 1)
        return;
    int whole_part_stock = static_cast<int>(food_stock_);
    nurturer.increment_food_stock_by(whole_part_stock);

    food_stock_ -= whole_part_stock;

    std::cout << "Transferring food.\n";
}

bool Provider::communicate(std::weak_ptr<Ant> wk_receiver)
{
    if (Ant::communicate(wk_receiver) == false)
        return false;

    std::cout << "Provider initiates communication.\n";

    Nurturer* cast_nurturer = dynamic_cast<Nurturer*>(wk_receiver.lock().get());
    if (cast_nurturer != nullptr)
        transferFood(*cast_nurturer);
    return true;
}
