#include "Texture.hpp"


SDL_Texture* Texture::LoadTexture(const char* texture){

    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* textur = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return textur;
}