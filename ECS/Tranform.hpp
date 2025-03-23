#ifndef Transform_hpp

#define Transform_hpp


#include "Components.hpp"

class TransformComponent : public Component {

    
    private:
    int xpos, ypos;

    public:

    TransformComponent(){
        xpos = 0;
        ypos = 0;
    }

    TransformComponent(int x, int y){
        xpos = x;
        ypos = y;
    }

    void update() override {
        xpos++;
        ypos++;
    }

    int x() {return xpos;}

    void x(int x) {xpos = x;}

    int y() {return ypos;}

    
    void y(int y) {ypos = y;}

    // void init() override {
    //     xpos = 0;
    //     ypos = 0;
    // }

   

    void setPos(int x, int y) {
        xpos = x;
        ypos = y;
    }
};

#endif