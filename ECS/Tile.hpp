#ifndef Tile_hpp

#define Tile_hpp


#include "ECS.hpp"
#include "Transform.hpp"
#include "Sprite.hpp"
#include "../Vector.hpp"
#include "../game.hpp"
#include "../Texture.hpp"
#include<string>


class TileComponent : public Component {
    public:
    SDL_Texture * texture;
	SDL_Rect srcRect, destRect;
	Vector position;
    TileComponent() = default;

    ~TileComponent()
	{
		SDL_DestroyTexture(texture);
	}

	TileComponent(int srcX, int srcY, int xpos, int ypos, int gsize, int gscale, std::string id)
	{
		texture = Game::assets->GetTexture(id);

        

		srcRect.x = srcX;
		srcRect.y = srcY;
		srcRect.w = srcRect.h = gsize;

		position.x = xpos;
		position.y = ypos;

        destRect.x = xpos;
        destRect.y = ypos;
		destRect.w = destRect.h = gsize * gscale;
	}

	void update() override
	{
		destRect.x = position.x - Game::camera.x;
		destRect.y = position.y - Game::camera.y;
	}

    void draw() override
	{
		Texture::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
		
	}
       
    
};



// class TileComponent : public Component
// {
// public:

// 	SDL_Texture * texture;
// 	SDL_Rect srcRect, destRect;
// 	Vector position;

// 	TileComponent() = default;

// 	~TileComponent()
// 	{
// 		SDL_DestroyTexture(texture);
// 	}

// 	TileComponent(int srcX, int srcY, int xpos, int ypos, int tsize, int tscale, std::string id)
// 	{
// 		texture = Game::assets->GetTexture(id);

// 		srcRect.x = srcX;
// 		srcRect.y = srcY;
// 		srcRect.w = srcRect.h = tsize;
// 		position.x = static_cast<float>(xpos);
// 		position.y = static_cast<float>(ypos);
// 		destRect.w = destRect.h = tsize * tscale;
// 	}

// 	void update() override
// 	{
// 		// destRect.x = static_cast<int>(position.x - Game::camera.x);
// 		// destRect.y = static_cast<int>(position.y - Game::camera.y);
//         destRect.x = static_cast<int>(position.x);
// 		destRect.y = static_cast<int>(position.y);
// 	}
// 	void draw() override
// 	{
// 		Texture::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
// 	}
// };


#endif