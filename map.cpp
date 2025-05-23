#include "Map.hpp"
#include "Texture.hpp"


#include "game.hpp"
#include <fstream>
#include "ECS/ECS.hpp"
#include "ECS/Components.hpp"

extern Manager manager;

Map::Map(std::string tID, int ms, int ts) : texID(tID), mapScale(ms), tileSize(ts)
{
     
}

Map::~Map()
{
    

}
void Map::LoadMap(std::string path, int sizeX, int sizeY){
    char c;
	std::fstream mapFile;
	mapFile.open(path);
    int srcX, srcY;

    for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			mapFile.get(c);
            srcY = atoi(&c) * tileSize;
            mapFile.get(c);
            srcX = atoi(&c) * tileSize;
            AddTile(srcX, srcY, x * (tileSize * mapScale), y * (tileSize * mapScale));
			
			mapFile.ignore();
		}
	}

	mapFile.ignore();

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			mapFile.get(c);
			if (c == '1')
			{
				auto& tcol(manager.addEntity());
				tcol.addComponent<ColliderComponent>("ground", x * (tileSize * mapScale), y * (tileSize * mapScale), (tileSize * mapScale));
				tcol.addGroup(Game::groupColliders);
				
			}
			mapFile.ignore();
		}
	}

    mapFile.close();


}

void Map::AddTile(int srcX, int srcY, int xpos, int ypos) {
	auto& tile(manager.addEntity());

    tile.addComponent<TileComponent>(srcX, srcY, xpos, ypos, tileSize, mapScale, texID);
    tile.addGroup(Game::groupMap);

}