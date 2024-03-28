#include <iostream>

#include "colony.hh"
#include "nurturer.hh"
#include "provider.hh"

int main()
{
    std::shared_ptr<Colony> myColony = std::make_shared<Colony>(10);

    Queen queen(myColony, DevelopmentStage::ADULT);
    queen.increment_food_level_by(3.4);

    std::cout << std::boolalpha << Colony::addAnt(queen, myColony) << " ";

    // create provider with luck_ = 1.32
    Provider provider(myColony, 1.32, DevelopmentStage::ADULT);

    // create nurturer with default luck and 54.289 food_stock_
    Nurturer nurturer(myColony, DevelopmentStage::ADULT);
    nurturer.increment_food_stock_by(54.289);

    // create larva with food_level_ = 3
    Provider larva(myColony, DevelopmentStage::LARVA);
    larva.increment_food_level_by(3);

    std::cout << std::boolalpha << Colony::addAnt(nurturer, myColony) << " ";
    std::cout << std::boolalpha << Colony::addAnt(larva, myColony) << " ";
    std::cout << std::boolalpha << Colony::addAnt(provider, myColony) << '\n';

    for (size_t i = 0; i < 8; i++)
        myColony->manageAnts();
    /*
     * Don't forget to test the communication methods of your ants.
     */
    return 0;
}
