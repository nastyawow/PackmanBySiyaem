#include "Object.hpp"

GameObject::GameObject(const char* texturesheet, int x, int y){


    Texture = Texture::LoadTexture(texturesheet);

    xpos = x;
    ypos = y;

};

void GameObject::update(){

    xpos++;
    ypos++;
    
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;



};

void GameObject::render(){
    SDL_RenderCopy(Game::renderer, Texture, &srcRect, &destRect);
};