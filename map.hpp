#ifndef Map_hpp
#define Map_hpp

#include "game.hpp"
#include <string>
class Map {
    public:
        Map(const char* mf, int ms, int ts);
        ~Map();

        void AddTile(int srcX, int srcY, int xpos, int ypos);
        void LoadMap(std::string path, int sizeX, int sizeY);
        // void DrawMap();

    private:

    const char* mapFilePath;
    int mapScale;
    int tileScale;

        // SDL_Rect src, dest;
        // SDL_Texture* sand;
        // SDL_Texture* stone;
        // SDL_Texture* wall;

        // int map[20][25];



};

#endif