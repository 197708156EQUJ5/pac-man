#include "pacman/EventRunner.hpp"

#include <iostream>
#include <memory>

int main(int argc, char* args[])
{
    std::unique_ptr<pacman::EventRunner> eventRunner = std::make_unique<pacman::EventRunner>();

    if (!eventRunner->init())
    {
        std::cout << "Could not initialize Pacman" << std::endl;
    }
    else
    {
        eventRunner->gameLoop();
    }

    eventRunner->close();

    return 0;
}
