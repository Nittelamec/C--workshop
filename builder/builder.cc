#include "builder.hh"

#include <memory>

#include "components.hh"

Car Builder::get_car() const
{
    Car car;
    car.body_ = get_body();
    car.engine_ = get_engine();
    car.wheels_ = { get_wheel(), get_wheel(), get_wheel(), get_wheel() };

    return car;
}

std::unique_ptr<Wheel> JeepBuilder::get_wheel() const
{
    return std::make_unique<Wheel>(Wheel(22));
}

std::unique_ptr<Engine> JeepBuilder::get_engine() const
{
    return std::make_unique<Engine>(Engine(400));
}

std::unique_ptr<Body> JeepBuilder::get_body() const
{
    return std::make_unique<Body>(Body("SUV"));
}

std::unique_ptr<Wheel> NissanBuilder::get_wheel() const
{
    return std::make_unique<Wheel>(Wheel(16));
}

std::unique_ptr<Engine> NissanBuilder::get_engine() const
{
    return std::make_unique<Engine>(Engine(85));
}

std::unique_ptr<Body> NissanBuilder::get_body() const
{
    return std::make_unique<Body>(Body("hatchback"));
}
