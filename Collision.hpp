#ifndef Collision_hpp
#define Collision_hpp
#include <SDL2/SDL.h>

class ColliderComponent;

class Collision
{
public:
	static bool AABB(const SDL_Rect& A, const SDL_Rect& B);
	static bool AABB(const ColliderComponent& cA, const ColliderComponent& cB);
};


#endif