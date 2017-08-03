#include "Classes.h"

Food::Food(int _x, int _y){
    this->setPos(_x, _y);
}
Food::Food(point _pos){
    this->setPos(_pos);
}

void  Food::setPos(int _x, int _y){
    this->pos.x = _x;
    this->pos.y = _y;
}
void  Food::setPos(point _pos){
    this->pos = _pos;
}
point Food::getPos(){
    return this->pos;
}
void  Food::setColor(int _color){
    this->color = _color;
}
int   Food::getColor(){
    return this->color;
}
