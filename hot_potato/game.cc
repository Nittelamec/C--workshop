#include "game.hh"

#include <iostream>
#include <memory>
#include <stdexcept>

#include "bomb.hh"
#include "player.hh"

void Game::add_player(const std::string& name, size_t nb_presses)
{
    players_.push_back(Player(name, nb_presses));
}

void Game::play(int bomb_ticks)
{
    if (players_.size() < 2)
        throw std::runtime_error("Not enough players");

    // init
    players_.front().set_bomb(std::make_unique<Bomb>(bomb_ticks));

    size_t i = 0;
    bool run = true;
    while (run)
    {
        size_t act = i;
        size_t next = (i + 1) % players_.size();

        try
        {
            players_.at(act).press_bomb();

            if (players_.at(act).is_dead())
            {
                std::cout << players_.at(act).get_name() << " has exploded.\n";
                run = false;
            }
            else
            {
                players_.at(act).pass_bomb(players_.at(next));
                i = (i + 1) == players_.size() ? 0 : i + 1;
            }
        }
        catch (std::runtime_error& e)
        {
            return;
        }
    }
}
