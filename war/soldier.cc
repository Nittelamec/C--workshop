#include "soldier.hh"

#include <iostream>

Soldier::Soldier()
{
    dmg_ = 3;
    hp_ = 15;
    scream_ = "No pity for losers!";
}

void Soldier::attack(Soldier& s)
{
    s.hp_ -= dmg_;
}

void Soldier::print_state() const
{
    std::cout << "I have " << hp_ << " health points.\n";
}

void Soldier::scream() const
{
    std::cout << scream_ << '\n';
}
