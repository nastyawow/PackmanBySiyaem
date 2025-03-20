// project_p.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// #define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>

const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char *argv[])
{
    //std::cout << "hello";
    
    SDL_Init( SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow( "Hello SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );

    if ( NULL == window) {
        std::cout << "no" << SDL_GetError();
        return 1;
    } 
    SDL_Event windowEvent;
    while( true ){
        if ( SDL_PollEvent( &windowEvent ) ){
            if ( SDL_QUIT == windowEvent.type) {
                break;
            }
        }
    }

    SDL_DestroyWindow( window);
    SDL_Quit();

    return EXIT_SUCCESS;


    //  я разобралась с гитом, уже победа
    
    // std::cout << "hello" ;
}
