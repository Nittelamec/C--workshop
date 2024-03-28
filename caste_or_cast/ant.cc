#include "ant.hh"

// The Colony class was forward declared in Ant header
// We need to include its header here so we know Colony implementation
#include "colony.hh"

Ant::Ant(std::shared_ptr<Colony> colony, DevelopmentStage stage)
    : stage_(stage)
    , colony_(colony)
{}

Ant::Ant(const Ant& o)
    : stage_(o.stage_)
    , colony_(o.colony_)
    , hp_(o.hp_)
    , food_level_(o.food_level_)
{}

Ant& Ant::operator=(const Ant& o)
{
    stage_ = o.stage_;
    colony_ = o.colony_;
    hp_ = o.hp_;
    food_level_ = o.food_level_;
    return *this;
}

std::shared_ptr<Colony> Ant::check_colony_access()
{
    std::shared_ptr<Colony> colony = colony_.lock();
    if (colony == nullptr)
        throw std::runtime_error("The Colony pointer is expired.");
    return colony;
}

bool Ant::communicate(std::weak_ptr<Ant> wk_receiver)
{
    std::shared_ptr<Ant> receiver = wk_receiver.lock();
    if (receiver == nullptr || stage_ != DevelopmentStage::ADULT
        || receiver->get_stage() != DevelopmentStage::ADULT)
        return false;
    if (receiver->get_passport_pheromone() != get_passport_pheromone())
        return attack(receiver);
    return true;
}

bool Ant::attack(std::weak_ptr<Ant> wk_ant)
{
    if (std::shared_ptr<Ant> ant = wk_ant.lock())
    {
        ant->hp_ -= 1;
        return true;
    }
    else
        return false;
}

uint32_t Ant::get_passport_pheromone()
{
    auto c = check_colony_access();
    return c->passport_pheromone_;
}

DevelopmentStage Ant::get_stage() const
{
    return stage_;
}

int Ant::get_hp() const
{
    return hp_;
}

void Ant::set_hp(int hp)
{
    hp_ = hp;
}

float Ant::get_food_level() const
{
    return food_level_;
}

void Ant::increment_food_level_by(float value)
{
    food_level_ += value;
}
