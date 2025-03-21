#include "Texture.hpp"

SDL_Texture* Texture::LoadTexture(const char* texture, SDL_Renederer* rend;){

    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* textur = SDL_CreateTextureFromSurface(rend, tempSurface);
    SDL_FreeSurface(tempSurface);

    return textur;
}