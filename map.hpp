#ifndef Map_hpp
#define Map_hpp

#include "game.hpp"

class Map {
    public:
        Map();
        ~Map();

        void LoadMap(int arr[20][25]);
        void DrawMap();

    private:

        SDL_Rect src, dest;
        SDL_Texture* sand;
        SDL_Texture* stone;
        SDL_Texture* wall;

        int map[20][25];



};

#endif