#ifndef Game_hpp
#define Game_hpp

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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

      static SDL_Renderer *renderer;

    private:
      int count = 0;
      bool isRunning;
      SDL_Window* window = nullptr;
	    SDL_Renderer* renderer = nullptr;
};

#endif