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
        position.x = 0.0f;
        position.y = 0.0f;
    }

    TransformComponent(int sc)
	{
		position.x = 0;
        position.y = 0;
		scale = sc;
	}

    TransformComponent(float x, float y){
        position.x = x;
        position.y = y;
    }
    TransformComponent(float x, float y, int h, int w, int s){
        position.x = x;
        position.y = y;
        height = h;
        width = w;
        scale = s;
    }


    void init() override {
            velocity.x = 0;
            velocity.y = 0;
        }

    void update() override {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }

    // int x() {return xpos;}
    // void x(int x) {xpos = x;}
    // int y() {return ypos;}
    // void y(int y) {ypos = y;}
    // 
    // void setPos(int x, int y) {
    //     xpos = x;
    //     ypos = y;
    // }
};

#endif