#include "pacman/EventRunner.hpp"

namespace pacman
{

EventRunner::~EventRunner()
{
    board->release();
    release();
}

bool EventRunner::init()
{
    board = std::make_unique<Board>();
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

    while (!quit)
    {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
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
                /* SDL_QUIT event (window release) */
                case SDL_QUIT:
                    quit = 1;
                    break;
                default:
                    break;
            }
            board->paintComponents();
        }
        
        //Update screen
        SDL_RenderPresent(renderer);
    }
}

void EventRunner::release()
{
    renderer = NULL;
}

} // namespace pacman

