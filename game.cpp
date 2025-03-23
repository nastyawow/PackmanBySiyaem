#include "game.hpp"

#include "Texture.hpp"

#include "Object.hpp"

#include "map.hpp"

#include "ECS.hpp"
#include "Components.hpp"

GameObject *player;
GameObject *enemy;
Map* map;


SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& newPlayer(manager.addEntity());

Game::Game() {}

Game::~Game() {}


void Game::init(const char* title, int width, int height, bool fullscreen) {

    int flag = 0;
    if(fullscreen) {
        flag = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == false){
        std::cout << "Initialised" << std::endl;
        window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flag);
        if(window){
            std::cout << "window created" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "renderer created" << std::endl;
        }
        isRunning = true;
    } else {
        isRunning = false;
    }

    player = new GameObject("assets/image.png", 0, 0);

    enemy = new GameObject("assets/image.png", 0, 0);

    map = new Map();

    newPlayer.addComponent<PositionComponent>();

    //SDL_Surface* tmpSurface = IMG_Load("assets/image.png");
    //playerTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    //SDL_FreeSurface(tmpSurface);

    // playerTexture = Texture::LoadTexture("assets/image.png", renderer); // - альтернативная запись
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            // switch(event.key.keysym.scancode){
            // case SDL_SCANCODE_A:
                
            //     break;
            // default:
            //     break;
            // }				
            break;
        case SDL_KEYUP:
            break;
        default:
            break;
        }
}

void Game::update() {
    // count++;
    // std::cout << count << std::endl;
    player->update();
    enemy->update();
    //map->LoadMap();

    manager.update();
    std::cout << newPlayer.getComponent<PositionComponent>().y() << "," << newPlayer.getComponent<PositionComponent>().y() << std::endl;
    
}

void Game::render() {
    SDL_RenderClear(renderer);
    map->DrawMap();
    player->render();
    enemy->render();

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit(); //руиним все :)
}
