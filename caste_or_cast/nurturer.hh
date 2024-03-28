#pragma once

#include "worker.hh"

/*
 * Nurturers worker sub-caste
 */
class Nurturer : public Worker
{
public:
    //! inherit Worker Constructors
    using Worker::Worker;
    //! final override of the work() Worker virtual method
    void work() override final;

    /*!
     * @details final override of the communicate() Ant virtual method
     * @return true if the communication succeeded
     * */
    bool communicate(std::weak_ptr<Ant> wk_receiver) override final;
    //! feed the queen
    void feedQueen();
    //! feed larvae
    void feedLarvae();
    //! clean the nest / colony
    void cleanNest();
};
