// project_p.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// #define SDL_MAIN_HANDLED
#include <iostream>

// Third-party library
#include <SDL2/SDL.h>

int main(int argc, char* argv[]){

    // if(SDL_Init(SDL_INIT_VIDEO) < 0){
    //     std::cout << "SDL could not be initialized: " <<
    //               SDL_GetError();
    // }else{
    //     std::cout << "SDL video system is ready to go\n";
    // }

    // return 0;

    SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	bool running = true;
	SDL_Event event;
	while (running)
	{
		while (SDL_PollEvent(&event)) {
			switch(event.type) {
			case SDL_QUIT:
				running = false;
				break;
			default:
				break;
			}
		}
		SDL_SetRenderDrawColor(renderer, 100, 55, 25, 255);
		SDL_RenderClear(renderer);

		// SDL_Rect rect = {};
		// rect.w = 100;
		// rect.h = 100;
		// rect.x = 0;
		// rect.y = 0;

		// SDL_RenderFillRect(renderer, rect);

		SDL_RenderPresent(renderer);
		SDL_Delay(16);
	}
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit(); //руиним все :)
	return 1;




    //yyeeeertgy



    //  я разобралась с гитом, уже победа
    
    // std::cout << "hello" ;
}
