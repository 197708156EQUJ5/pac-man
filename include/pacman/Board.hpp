#pragma once

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

private:
    
};

} // namespace pacman

