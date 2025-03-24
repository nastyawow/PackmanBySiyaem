#include "game.hpp"

#include "Texture.hpp"

#include "Object.hpp"




#include "ECS/ECS.hpp"
#include "ECS/Components.hpp"
#include "ECS/Transform.hpp"



#include "Map.hpp"
#include "Vector.hpp"

#include "Collision.hpp"
#include "ECS/Collider.hpp"
// #include "ECS/Position.hpp"
// #include "ECS/Sprite.hpp"

// GameObject *player;
// GameObject *enemy;
Map *map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<ColliderComponent*> Game::colliders;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());

const char* mapfile = "assets/sss.png";

bool Game::isRunning = false;

// enum groupLabels : std::size_t {
//     groupMap,
//     groupPlayers,
//     groupEnemies;
//     groupColliders;
// }

// auto& tile0(manager.addEntity());
// auto& tile1(manager.addEntity());
// auto& tile2(manager.addEntity());


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

    // player = new GameObject("assets/image.png", 0, 0);

    // enemy = new GameObject("assets/image.png", 0, 0);

    map = new Map();
    Map::LoadMap("assets/map.map", 29, 33);

    

    player.addComponent<TransformComponent>(4);
    player.addComponent<SpriteComponent>("assets/player_anims.png", true);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");

   
    

    // playerEntity.addComponent<PositionComponent>();
    // playerEntity.getComponent<PositionComponent>().setPos(10,10);

    // newPlayer.addComponent<PositionComponent>();

    //SDL_Surface* tmpSurface = IMG_Load("assets/image.png");
    //playerTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    //SDL_FreeSurface(tmpSurface);

    // playerTexture = Texture::LoadTexture("assets/image.png", renderer); // - альтернативная запись
}

void Game::handleEvents() {
    
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
    manager.refresh();
    manager.update();
    for(auto cc : colliders){
        Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
    }
    
    // player.getComponent<TransformComponent>().position.Add(Vector(5, 0));
    // if(player.getComponent<TransformComponent>().position.x > 100){
    //     player.getComponent<SpriteComponent>().setTex("assets/image.png");
    // }



    // player->update();
    // enemy->update();
    // map->LoadMap();

    
    // std::cout << newPlayer.getComponent<PositionComponent>().y() << "," << newPlayer.getComponent<PositionComponent>().y() << std::endl;
    
}

void Game::render() {
    SDL_RenderClear(renderer);
    // map->DrawMap();
    // player->render();
    // enemy->render();

    manager.draw();

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit(); //руиним все :)
}

void Game::AddTile(int srcX, int srcY, int xpos, int ypos) {
    auto& tile(manager.addEntity());

    tile.addComponent<TileComponent>(srcX, srcY, xpos, ypos, mapfile);
}
