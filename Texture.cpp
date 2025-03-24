#include "Texture.hpp"


SDL_Texture* Texture::LoadTexture(const char* texture){

    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* textur = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return textur;
}

void Texture::Draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip){
    SDL_RenderCopyEx(Game::renderer, tex, &src, &dest, 0, NULL, flip);
}