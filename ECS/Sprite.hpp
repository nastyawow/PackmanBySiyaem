#ifndef Sprite_hpp

#define Sprite_hpp

#include "Components.hpp"
#include "../Texture.hpp"
#include "../SDL.h"
#include "Animation.hpp"
#include <map>
#include "../Asset.hpp"

class SpriteComponent : public Component
{
    private:
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;

    bool animated = false;
	int frames = 0;
	int speed = 100;


    public:

    int animIndex = 0;
    std::map<const char*, Animation> animations;

    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

    SpriteComponent() = default;
    SpriteComponent(const char* path)
    {
        setTex(path);

    }
    SpriteComponent(std::string id, bool isAnimated)
    {
		animated = isAnimated;

		Animation idle = Animation(0, 5, 300);
		Animation walk = Animation(1, 4, 300);

		animations.emplace("Idle", idle);
		animations.emplace("Walk", walk);

		Play("Idle");

		setTex(id);
	}
    ~SpriteComponent(){
        // SDL_DestroyTexture(texture);
    }

    void setTex(std::string id) {
        texture = Game::assets->GetTexture(id);
    }

    void init() override {

        transform = &entity->getComponent<TransformComponent>();

        srcRect.x  = srcRect.y = 0;
        srcRect.w  = transform->width;
        srcRect.h = transform->height;
        

    }
    void update() override {

        if (animated)
		{
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}

        srcRect.y = animIndex * transform->height;

        destRect.x = static_cast<int>(transform->position.x) - Game::camera.x;
		destRect.y = static_cast<int>(transform->position.y) - Game::camera.y;
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;

    }
    void draw() override {
        Texture::Draw(texture, srcRect, destRect, spriteFlip);

    }

    void Play(const char* animName)
	{
		frames = animations[animName].frames;
		animIndex = animations[animName].index;
		speed = animations[animName].speed;
	}

};

#endif