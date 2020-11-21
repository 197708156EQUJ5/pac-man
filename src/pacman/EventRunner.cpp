#include "pacman/EventRunner.hpp"
#include "pacman/Board.hpp"

#include <iostream>
#include <sstream>

namespace pacman
{

EventRunner::EventRunner()
{
}

bool EventRunner::init()
{
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

        //Create window
        window = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                Board::WIDTH, Board::HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;;
            success = false;
        }
        else
        {
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
            cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENS);
            SDL_SetCursor(cursor);
        }
    }
    
    //atomTexture.setRenderer(renderer);

    if (!loadMedia())
    {
        success = false;
    }

    return success;    
}

void EventRunner::gameLoop()
{
    bool quit = false;
    SDL_Event event;

    while(!quit)
    {
        SDL_SetRenderDrawColor(renderer, 0xa9, 0xa9, 0xa9, 0xFF);
        SDL_RenderClear(renderer);

        
        //Handle events on queue
        while(SDL_PollEvent(&event) != 0)
        {
            switch(event.type)
            {
                /* Keyboard event */
                /* Pass the event data onto PrintKeyInfo() */
                case SDL_KEYDOWN:
                case SDL_KEYUP:
                    //PrintKeyInfo( &event.key );
                    break;
                /* SDL_QUIT event (window close) */
                case SDL_QUIT:
                    quit = 1;
                    break;
                default:
                    break;
            }            
        }
        
        //Update screen
        SDL_RenderPresent(renderer);
    }
}

bool EventRunner::loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load dot texture
    //if(!atomTexture.loadFromFile("resources/red_dot_20x20.png"))
    //{
    //    std::cout << "Failed to load dot texture!" << std::endl;
    //    success = false;
    //}

    return success;
}

void EventRunner::close()
{
    //Free loaded images
    //atomTexture.free();

    //Destroy window    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

} // namespace pacman

