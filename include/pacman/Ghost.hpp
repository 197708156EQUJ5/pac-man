#pragma once

#include "Character.hpp"

namespace pacman
{

class Ghost : Character
{
public:

    Ghost() = default;
    ~Ghost() = default;

    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    void setDirection(Direction &direction);
    void move();
    void respawn();
};

} // namespace pacman

