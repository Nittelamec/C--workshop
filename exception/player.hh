#pragma once

#include <iostream>

#include "invalid_argument.hh"

class Player
{
public:
    Player(const std::string& name, unsigned int age, int guess);

    int get_guess() const;

    friend std::ostream& operator<<(std::ostream& os, const Player& b);

private:
    std::string name_;
    unsigned int age_;

    int guess_;
};

std::ostream& operator<<(std::ostream& os, const Player& p);
