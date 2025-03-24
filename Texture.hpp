#ifndef Texture_hpp

#define Texture_hpp

#include "game.hpp"

class Texture {
    public:
        static SDL_Texture* LoadTexture(const char* name);
        static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip);

    private:


};

#endif