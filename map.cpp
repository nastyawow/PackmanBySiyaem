#include "Map.hpp"
#include "Texture.hpp"


#include "game.hpp"
#include <fstream>


Map::Map()
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
            srcY = atoi(&c) * 32;
            mapFile.get(c);
            srcX = atoi(&c) * 32;
            Game::AddTile(srcX, srcY, x * 32, y * 32);
			// if (c == '1')
			// {
			// 	auto& tcol(manager.addEntity());
			// 	tcol.addComponent<ColliderComponent>("terrain", x * scaledSize, y * scaledSize, scaledSize);
			// 	tcol.addGroup(Game::groupColliders);
			// }
			mapFile.ignore();
		}
	}

    mapFile.close();


}
// void Map::DrawMap(){
//     int type = 0;
//     for (int row = 0; row < 20; row++){
//         for (int col = 0; col < 20; col++){
//             type = map[row][col];

//             dest.x = col * 32;
//             dest.y = row * 32;

//             switch (type){
//                 case 0:
//                     Texture::Draw(wall, src, dest);
//                     break;

//                 case 1:
//                     Texture::Draw(sand, src, dest);
//                     break;

//                 case 2:
//                     Texture::Draw(stone, src, dest);
//                     break;

//                 default:
//                 break;
//             }
//         }
//     }


// }