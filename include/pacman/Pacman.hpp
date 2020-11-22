#pragma once

#include "Character.hpp"

namespace pacman
{

class Pacman : Character
{
public:

    Pacman() = default;
    ~Pacman() = default;

    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    void setDirection(Direction &direction);
    void move();
    void respawn();
};

} // namespace pacman

