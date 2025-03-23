#include "Vector.hpp"

Vector::Vector(){
    x = 0.0f;
    y = 0.0f;

}

Vector::Vector(float x, float y) {
    this->x = x;
    this->y = y;
}

Vector& Vector::Add(const Vector& vec){
    this->x  += vec.x;
    this->y += vec.y;

    return *this;
}
Vector& Vector::Subtract(const Vector& vec){
    this->x  -= vec.x;
    this->y -= vec.y;

    return *this;
}
Vector& Vector::Multiply(const Vector& vec){
    this->x  *= vec.x;
    this->y *= vec.y;

    return *this;
}
Vector& Vector::Divide(const Vector& vec){
    this->x  /= vec.x;
    this->y /= vec.y;

    return *this;
}