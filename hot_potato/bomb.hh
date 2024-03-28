#pragma once

class Bomb
{
public:
    Bomb(int ticks);

    void tick();

    bool has_exploded() const;

private:
    int max_ticks_;
    int count_;
};
