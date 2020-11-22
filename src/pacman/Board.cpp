#include "pacman/Board.hpp"

#include <iostream>
#include <sstream>

namespace pacman
{

Board::Board() :
    spriteManager(nullptr),
    window(nullptr),
    renderer(nullptr)
{
}

bool Board::init()
{
    std::cout << "Board Init" << std::endl;;
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;;
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            std::cout << "Warning: Linear texture filtering not enabled!" << std::endl;;
        }

        std::cout << "creating window..." << std::endl;
        //Create window
        window = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
        std::cout << "after creating window..." << std::endl;
        if (window == NULL)
        {
            std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;;
            success = false;
        }
        else
        {
            std::cout << "created window" << std::endl;
            //Create vsynced renderer for window
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (renderer == NULL)
            {
                std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;;
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;;
                    success = false;
                }
            }
        }
    }

    std::cout << "Success" << std::endl;
    
    //atomTexture.setRenderer(renderer);

    if (!initSpriteManager())
    {
        success = false;
    }

    return success;    
}

bool Board::checkCollision()
{
}

bool Board::initSpriteManager()
{
    return spriteManager->loadMedia();
}

SDL_Renderer* Board::getRenderer()
{
    return renderer;
}

void Board::close()
{
    //Free loaded images
    //atomTexture.free();

    //Destroy window    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;
    spriteManager = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

}