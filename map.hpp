#ifndef Map_hpp
#define Map_hpp

#include "game.hpp"
#include <string>
class Map {
    public:
        Map(std::string tID, int ms, int ts);
        ~Map();

        void AddTile(int srcX, int srcY, int xpos, int ypos);
        void LoadMap(std::string path, int sizeX, int sizeY);
        // void DrawMap();

    private:
    std::string texID;
    const char* mapFilePath;
    int mapScale;
    int tileSize;

        



};

#endif

