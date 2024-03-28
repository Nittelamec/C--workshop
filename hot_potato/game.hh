#pragma once

#include <string>
#include <vector>

#include "player.hh"

class Game
{
public:
    Game() = default;

    void add_player(const std::string& name, size_t nb_presses);
    void play(int bomb_ticks);

private:
    std::vector<Player> players_;
};
