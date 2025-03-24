#ifndef Components_hpp

#define Components_hpp

#include "../game.hpp"
#include "ECS.hpp"
#include "Transform.hpp"
#include "Sprite.hpp"
#include "Keyboard.hpp"
#include "Collider.hpp"
#include "Tile.hpp"
#include "Projectile.hpp"

// class PositionComponent : public Component {
//     private:
//     int xpos, ypos;

//     public:
//     int x() {return xpos;}
//     int y() {return ypos;}

//     void init() override {
//         xpos = 0;
//         ypos = 0;
//     }

//     void update() override {
//         xpos++;
//         ypos++;
//     }

//     void setPos(int x, int y) {
//         xpos = x;
//         ypos = y;
//     }
// };



#endif