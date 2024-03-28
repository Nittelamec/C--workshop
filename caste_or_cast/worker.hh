#pragma once

#include "ant.hh"

/*
 * Class representing the generic Worker Caste
 */
class Worker : public Ant
{
public:
    //! inherit Ant constructors
    using Ant::Ant;
    //! constructor
    Worker(std::shared_ptr<Colony> colony, float luck,
           DevelopmentStage stage = DevelopmentStage::EGG);
    //! the Worker will do all of its tasks
    virtual void work();
    //! getter for food_stock_
    float get_food_stock() const;
    //! add given value to food_stock_
    void increment_food_stock_by(float value);
    //! return the luck of the worker
    float get_luck() const;

protected:
    //! current food that the worker store on her.
    float food_stock_ = 0.0;
    //! luck of the worker
    float luck_ = 3.141592;
};
