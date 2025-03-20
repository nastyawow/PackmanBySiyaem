// project_p.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// #define SDL_MAIN_HANDLED
#include <iostream>

// Third-party library
#include <SDL2/SDL.h>

int main(int argc, char* argv[]){

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL could not be initialized: " <<
                  SDL_GetError();
    }else{
        std::cout << "SDL video system is ready to go\n";
    }

    return 0;

    //yyeeeertgy



    //  я разобралась с гитом, уже победа
    
    // std::cout << "hello" ;
}
