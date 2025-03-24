#ifndef Object_hpp
#define Object_hpp

#include "game.hpp"

#include "Texture.hpp"





class GameObject {
    public:
        GameObject(const char* texturesheet, int x, int y);
        ~GameObject();

        void update();
        void render();

    private:
        int xpos;
        int ypos;

        SDL_Texture* Texture;
        SDL_Rect srcRect, destRect;
        SDL_Renderer* renderer;

};

#endif