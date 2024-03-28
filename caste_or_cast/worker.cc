#include "worker.hh"

Worker::Worker(std::shared_ptr<Colony> colony, float luck,
               DevelopmentStage stage)
    : Ant(colony, stage)
    , luck_(luck)
{}

void Worker::work()
{
    if (food_level_ < 0)
        hp_ -= 0.5;
}

float Worker::get_luck() const
{
    return luck_;
}

float Worker::get_food_stock() const
{
    return food_stock_;
}

void Worker::increment_food_stock_by(float value)
{
    food_stock_ += value;
}
