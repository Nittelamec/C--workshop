#include "bomb.hh"

#include <iostream>
#include <stdexcept>

Bomb::Bomb(int ticks)
    : max_ticks_(ticks)
    , count_(0)
{
    if (ticks <= 0)
        throw std::runtime_error("Ticks must be positive");
}

void Bomb::tick()
{
    if (count_ % 2 == 0)
        std::cout << "Tic!\n";
    else
        std::cout << "Tac!\n";

    if (count_ >= max_ticks_)
        throw std::runtime_error("The bomb has already exploded");
    else
        count_ += 1;
}

bool Bomb::has_exploded() const
{
    return (count_ >= max_ticks_);
}
