#include "game.hh"

#include <iostream>

#include "invalid_argument.hh"
#include "player.hh"

Game::Game(int secret)
    : secret_(secret)
{}

void Game::play(const Player& p1, const Player& p2) const
{
    if (std::addressof(p1) == std::addressof(p2))
        throw InvalidArgumentException("Stop playing by yourself!");

    auto d1 = std::abs(p1.get_guess() - secret_);
    auto d2 = std::abs(p2.get_guess() - secret_);

    if (d1 > d2)
        std::cout << p1 << " wins!" << std::endl;
    else if (d1 < d2)
        std::cout << p2 << " wins!" << std::endl;
    else
        std::cout << "Draw!" << std::endl;
}
