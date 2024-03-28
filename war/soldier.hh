#pragma once

#include <string>

class Soldier
{
public:
    Soldier();
    void attack(Soldier& s);
    void print_state() const;
    void scream() const;

protected:
    unsigned int dmg_;
    int hp_;
    std::string scream_;
};
