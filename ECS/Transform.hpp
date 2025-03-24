#ifndef Transform_hpp

#define Transform_hpp


#include "Components.hpp"
#include "../Vector.hpp"

struct TransformComponent : public Component {

    Vector position;
    Vector velocity;
    int speed = 3;

    int height = 32;
    int width = 32;
    int scale = 1;


    TransformComponent(){
        position.Zero();
    }

    TransformComponent(int sc)
	{
		position.x = 128;
        position.y = 128;
		scale = sc;
	}

    TransformComponent(float x, float y){
        position.Zero();
    }
    TransformComponent(float x, float y, int h, int w, int s){
        position.x = x;
        position.y = y;
        height = h;
        width = w;
        scale = s;
    }


    void init() override {
            velocity.Zero();
        }

    void update() override {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;

    }


};

#endif