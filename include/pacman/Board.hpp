#pragma once

#include "pacman/Ghost.hpp"
#include "pacman/Pacman.hpp"
#include "pacman/SpriteManager.hpp"

#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

namespace pacman
{

class Board
{
public:
    
    Board();
    ~Board() = default;

    //Screen dimension constants
    static const int WIDTH = 672;
    static const int HEIGHT = 864;

    bool checkCollision();
    bool init();
    void close();
    SDL_Renderer* getRenderer();

private:
   
    uint32_t score;
    uint32_t lives;
    std::unique_ptr<Pacman> pacman;
    std::unique_ptr<Ghost> blinky;
    std::unique_ptr<Ghost> pinky;
    std::unique_ptr<Ghost> inky;
    std::unique_ptr<Ghost> clyde;
    
    SDL_Window* window;
    SDL_Renderer* renderer;
    SpriteManager* spriteManager;
    
    bool initSpriteManager();

};

} // namespace pacman

