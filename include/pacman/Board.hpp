#pragma once

#include "Pacman.hpp"
#include "Ghost.hpp"

#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

namespace pacman
{

class Board
{
public:
    
    Board() = default;
    ~Board() = default;

    //Screen dimension constants
    static const int WIDTH = 672;
    static const int HEIGHT = 864;

    bool checkCollision();

private:
   
    uint32_t score;
    uint32_t lives;
    std::unique_ptr<Pacman> pacman;
    std::unique_ptr<Ghost> blinky;
    std::unique_ptr<Ghost> pinky;
    std::unique_ptr<Ghost> inky;
    std::unique_ptr<Ghost> clyde;

};

} // namespace pacman

