#pragma once

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

namespace pacman
{

class SpriteManager
{
    public:

        SpriteManager();
        ~SpriteManager() = default;

        bool loadMedia();

    private:

        static const std::string SPRITE_SHEET;
        SDL_Texture* spriteSheetTexture;
        SDL_Renderer* renderer;
};

} // namespace pacman

