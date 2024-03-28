#pragma once

#include <queue>

#include "ant.hh"

//! forward declaration
class Worker;

/*
 * Class representing the Queen Caste
 */
class Queen : public Ant
{
public:
    //! inherit Ant Constructors
    using Ant::Ant;
    //! the queen will create either a new Provider or Nurturer and push it to
    //! eggs_queue_
    void layEgg();

private:
    /*!
     * We should not modify the Colony::workers vector while we
     * iterate over it (because in some cases it can lead to undefined behavior)
     * To solve this problem, we use a queue so we can save the eggs that the
     * queen lay in one round (i.e one call of Colony::manageAnts) and insert
     * them in workers_ vector after we finished iterating.
     * */
    std::queue<std::shared_ptr<Worker>> eggs_queue_;
    friend class Colony;
};
