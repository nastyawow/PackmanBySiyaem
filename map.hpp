#ifndef Map_hpp
#define Map_hpp

#include "game.hpp"
#include <string>
class Map {
    public:
        Map();
        ~Map();

        static void LoadMap(std::string path, int sizeX, int sizeY);
        // void DrawMap();

    private:

        // SDL_Rect src, dest;
        // SDL_Texture* sand;
        // SDL_Texture* stone;
        // SDL_Texture* wall;

        // int map[20][25];



};

#endif