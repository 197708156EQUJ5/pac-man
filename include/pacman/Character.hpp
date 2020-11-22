#pragma once

namespace pacman
{

enum class Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Character
{
public:
    virtual int getX();
    virtual int getY();
    virtual void setX(int x);
    virtual void setY(int y);
    virtual void setDirection(Direction &direction);
    virtual void move();
    virtual void respawn();
};

} // namespace pacman

