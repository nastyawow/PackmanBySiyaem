#ifndef Game_hpp
#define Game_hpp

#include <iostream>

#include <SDL2/SDL.h>
#include <stdio.h>

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

    private:
      bool isRunning;
      SDL_Window* window = nullptr;
	    SDL_Renderer* renderer = nullptr;
};

#endif