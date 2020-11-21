#pragma once

#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

namespace pacman
{

class EventRunner
{
public:
    
    EventRunner();
    ~EventRunner() = default;

    bool init();
    void close();
    void gameLoop();
    bool loadMedia();

private:
    
    SDL_Cursor* cursor;
    SDL_Window* window;
    SDL_Renderer* renderer;

};

} // namespace pacman

