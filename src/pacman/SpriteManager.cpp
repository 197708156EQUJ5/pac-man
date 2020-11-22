#include "pacman/SpriteManager.hpp"

namespace pacman
{

const std::string SpriteManager::SPRITE_SHEET("resources/pacman-spritesheet.png");

SpriteManager::SpriteManager() :
    spriteSheetTexture(NULL),
    renderer(renderer)
{
}

bool SpriteManager::loadMedia()
{
    bool success = true;

    SDL_Surface* loadedSurface = IMG_Load(SPRITE_SHEET.c_str());

    if(loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", SPRITE_SHEET.c_str(), IMG_GetError());
    }
    else
    {
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

        //Create texture from surface pixels
        spriteSheetTexture = SDL_CreateTextureFromSurface(this->renderer, loadedSurface);
        if (spriteSheetTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", SPRITE_SHEET.c_str(), SDL_GetError());
            success = false;
        }
        else
        {
            success = true;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return success;
}

} // namespace pacman
