#ifndef Asset_hpp
#define Asset_hpp

#include <map>
#include <string>
#include "Texture.hpp"
#include "Vector.hpp"
#include "ECS\ECS.hpp"

class AssetManager
{
public:
	AssetManager(Manager* man);
	~AssetManager();

	void CreateProjectile(Vector pos, Vector vel, int range, int speed, std::string id);

	//texture management
	void AddTexture(std::string id, const char* path);
	SDL_Texture* GetTexture(std::string id);


private:

	Manager* manager;
	std::map<std::string, SDL_Texture*> textures;
	
};

#endif