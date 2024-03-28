#pragma once

#include "worker.hh"

//! forward declaration
class Nurturer;

/*
 * Provider worker sub-caste :
 *   harvest Food in the Outside World and transmit it to
 *   Nurturers ants
 */
class Provider : public Worker
{
public:
    //! inherit Worker Constructors
    using Worker::Worker;
    //! final override of the work() Worker virtual method
    void work() override final;
    //!  transfer food to Nurturer workers only
    void transferFood(Nurturer& nurturer);
    /*!
     * @details final override of the communicate() Ant virtual method
     * @return true if the communication succeeded
     * */
    bool communicate(std::weak_ptr<Ant> wk_receiver) override final;
    //! go to the outside world and harvest food
    void harvestFood();
};
