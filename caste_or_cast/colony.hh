#pragma once

#include <vector>

#include "queen.hh"
#include "worker.hh"

//! forward declarations
class Provider;
class Nurturer;

/*
 * Colony class that acts as one entity and manage all of its ants
 */
class Colony
{
public:
    //! constructor
    Colony(uint32_t passport);
    //! static method that adds a COPY of the given ant to the given colony
    static bool addAnt(const Ant& ant, std::shared_ptr<Colony> colony);
    //! manage all the ants, can be understood as one round
    void manageAnts();
    //! overall cleanliness of the colony
    float cleanliness = 100;

private:
    //! manage the queen (is alive etc)
    void manageQueen();
    //! remove all the dead workers of the workers_ vector
    void removeDeadWorkers();
    //! attribute used to recognise if an Ant is from the same colony
    uint32_t passport_pheromone_;
    //! vector of all workers of the colony, each worker is stored in a
    //! shared_ptr
    std::vector<std::shared_ptr<Worker>> workers_;
    //! unique queen, only its colony have the ownership of it.
    std::unique_ptr<Queen> queen_ = nullptr;

    //! friend classes
    friend class Ant;
    friend class Nurturer;
};
