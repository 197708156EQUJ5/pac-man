#include "pacman/EventRunner.hpp"

namespace pacman
{

EventRunner::~EventRunner()
{
    board->close();
    close();
}

bool EventRunner::init()
{
    if (board->init())
    {
        renderer = board->getRenderer();
        return true;
    }
    
    return true;
}

void EventRunner::gameLoop()
{
    std::cout << "Entering game loop" << std::endl;
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

void EventRunner::close()
{
    renderer = NULL;
}

} // namespace pacman

