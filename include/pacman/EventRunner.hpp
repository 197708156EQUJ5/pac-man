#pragma once

#include "pacman/Board.hpp"

#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

namespace pacman
{

class EventRunner
{
public:
    
    EventRunner() = default;
    ~EventRunner();

    bool init();
    void gameLoop();

private:
    
    SDL_Renderer* renderer = NULL;
    Board* board = NULL;

    void close(); 
};

} // namespace pacman

