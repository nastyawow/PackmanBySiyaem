#include "game.hpp"

#include "Texture.hpp"

// #include "Object.hpp"





#include "ECS/Components.hpp"
#include "ECS/Transform.hpp"



#include "Map.hpp"
#include "Vector.hpp"

#include "Collision.hpp"
#include "ECS/Collider.hpp"
#include "ECS/ECS.hpp"
#include "ECS/ECS.cpp"
// #include "ECS/Position.hpp"
// #include "ECS/Sprite.hpp"

// GameObject *player;
// GameObject *enemy;
Map *map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

SDL_Rect Game::camera = {0,0, 1952, 2528};

AssetManager* Game::assets = new AssetManager(&manager);

auto& player(manager.addEntity());


const char* mapfile = "assets/sss.png";

bool Game::isRunning = false;



// auto& tile0(manager.addEntity());
// auto& tile1(manager.addEntity());
// auto& tile2(manager.addEntity());

auto& tiles(manager.getGroup(Game::groupMap));
auto& players(manager.getGroup(Game::groupPlayers));
auto& colliders(manager.getGroup(Game::groupColliders));
auto& projectiles(manager.getGroup(Game::groupProjectiles));


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


    assets->AddTexture("ground", "assets/sss.png");
	assets->AddTexture("player", "assets/player_anims.png");
	// assets->AddTexture("projectile", "assets/proj.png");


    map = new Map("ground", 3, 32);
    map->LoadMap("assets/map.map", 29, 33);

    

    player.addComponent<TransformComponent>(2);
    player.addComponent<SpriteComponent>("player", true);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    player.addGroup(groupPlayers);

   
    

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
    SDL_Rect playerCol = player.getComponent<ColliderComponent>().collider;
    Vector playerPos = player.getComponent<TransformComponent>().position;

    manager.refresh();
    manager.update();

    for (auto& c : colliders)
	{
		SDL_Rect cCol = c->getComponent<ColliderComponent>().collider;
		if (Collision::AABB(cCol, playerCol))
		{
			player.getComponent<TransformComponent>().position = playerPos;
		}
	}


    camera.x = player.getComponent<TransformComponent>().position.x - 464;
    camera.y = player.getComponent<TransformComponent>().position.y - 320;

    if (camera.x < 0)
		camera.x = 0;
	if (camera.y < 0)
		camera.y = 0;
	if (camera.x > camera.w)
		camera.x = camera.w;
	if (camera.y > camera.h)
		camera.y = camera.h;



    
    
}



void Game::render() {
    SDL_RenderClear(renderer);
    // map->DrawMap();
    // player->render();
    // enemy->render();

    // manager.draw();


    for (auto& t : tiles){
        t->draw();
    }
    for (auto& c : colliders)
	{
		c->draw();
	}

	for (auto& p : players)
	{
		p->draw();
	}


    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit(); //руиним все :)
}

// void Game::AddTile(int srcX, int srcY, int xpos, int ypos) {
    
// }
