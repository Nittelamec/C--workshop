#include "queen.hh"

#include <iostream>

#include "colony.hh"
#include "nurturer.hh"
#include "provider.hh"
#include "worker.hh"

void Queen::layEgg()
{
    std::cout << "Queen is laying an Egg.\n";
    // if the queen tries to lay an egg without enough food_level
    // it loses a health point
    if (food_level_ < 0)
        hp_ -= 1;
    // checking if the colony_ attribute is not expired
    std::shared_ptr<Colony> colony = check_colony_access();
    // either create a new Provider or a new Nurturer
    static bool choose = false;
    if (choose)
        eggs_queue_.emplace(std::make_shared<Provider>(
            colony, food_level_ * 0.5 + 0.2, DevelopmentStage::EGG));
    else
        eggs_queue_.emplace(std::make_shared<Nurturer>(
            colony, food_level_ * 0.1 + 0.13, DevelopmentStage::EGG));
    choose = !choose;
    // consequences of laying an egg
    colony->cleanliness -= 0.6;
    food_level_ -= 5.7;
}
