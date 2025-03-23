#ifndef Sprite_hpp

#define Sprite_hpp

#include "Components.hpp"
#include "../SDL.h"

class SpriteComponent : public Component
{
    private:
    TransformComponent *tranform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;

    public:

    SpriteComponent() = default;
    SpriteComponent(const char* path)
    {
        setTex(path);

    }

    void setTex(const char* path) {
        texture = Texture::LoadTexture(path);
    }

    void init() override {

        tranform = &entity->getComponent<PositionComponent>();

        srcRect.x  = srcRect.y = 0;
        srcRect.w  = srcRect.h = 32;
        destRect.w = destRect.h = 64;

    }
    void update() override {
        destRect.x = tranform->x();
        destRect.y = tranform->y();

    }
    void draw() override {
        Texture::Draw(texture, srcRect, destRect);

    }

};

#endif