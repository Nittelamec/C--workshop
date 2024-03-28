#pragma once

#include <memory>
#include <string>

#include "bomb.hh"

class Player
{
public:
    Player(const std::string& name, size_t nb_presses);

    void pass_bomb(Player& receiver);
    void press_bomb();

    bool has_bomb() const;
    bool is_dead() const;

    void set_bomb(std::unique_ptr<Bomb> bomb);
    const std::string& get_name() const;

private:
    std::string name_;
    std::unique_ptr<Bomb> bomb_;
    size_t nb_presses_;
};
