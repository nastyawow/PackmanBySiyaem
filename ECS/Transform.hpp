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
		position.Zero();
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