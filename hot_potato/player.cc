#include "player.hh"

#include <iostream>
#include <stdexcept>
#include <string>

Player::Player(const std::string& name, size_t nb_presses)
    : name_(name)
    , bomb_(nullptr)
    , nb_presses_(nb_presses)
{}

void Player::pass_bomb(Player& receiver)
{
    if (bomb_ == nullptr || receiver.has_bomb())
        throw std::runtime_error("No bomb available or the receiver have one");

    std::cout << name_ << " passes the bomb to " << receiver.get_name() + ".\n";
    receiver.set_bomb(std::move(bomb_));
}

void Player::press_bomb()
{
    if (bomb_ == nullptr)
        throw std::runtime_error("No bomb available");
    for (size_t i = 0; i < nb_presses_; i++)
    {
        if (!bomb_->has_exploded())
            bomb_->tick();
    }
}

bool Player::has_bomb() const
{
    return (bomb_ != nullptr);
}

bool Player::is_dead() const
{
    return (bomb_ != nullptr && bomb_->has_exploded());
}

void Player::set_bomb(std::unique_ptr<Bomb> bomb)
{
    bomb_ = std::move(bomb);
}

const std::string& Player::get_name() const
{
    return name_;
}
