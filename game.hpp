#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <vector>


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "Asset.hpp"

class ColliderComponent;

class Game{
    public:
      Game();
      ~Game();
      
      void init(const char* title, int width, int height, bool fullscreen);

      void handleEvents();
      void update();
      void render();
      void clean();
      bool running(){
        return isRunning;
      };

      

      
      static SDL_Renderer *renderer;
      static SDL_Event event;
     
      static bool isRunning;
      static SDL_Rect camera;
      static AssetManager* assets;

      enum groupLabels : std::size_t
      {
        groupMap,
        groupPlayers,
        groupColliders,
        groupProjectiles
      };

    private:
      int count = 0;
      
      SDL_Window* window = nullptr;
	    // SDL_Renderer* renderer = nullptr;
};

#endif