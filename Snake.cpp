#include "Classes.h"
#include <stdlib.h>

using namespace std;

Snake::Snake(int _x, int _y){
    setPosition(_x, _y);
}

Snake::Snake(point _pos){
    setPosition(_pos);
}

Snake::~Snake() {}

void Snake::setPosition(int _x, int _y){
    pos.x = _x;
    pos.y = _y;
}

void Snake::setPosition(point _pos){
    pos = _pos;
}

point Snake::getPosition(){
    return pos;
}

void Snake::setTailLen(int _len){
    tailLen = _len;
}

int Snake::getTailLen(){
    return tailLen;
}

void Snake::setDirection(SnakeDirection _direction, bool _antiReverse)
{
    if (_antiReverse)
    {
        if ( abs(getDirection() - _direction) != 1 ) //==1 is reversed case
            direction = _direction;
    }
    else
        direction = _direction;
}

SnakeDirection Snake::getDirection(){
    return direction;
}

void Snake::insertTails(point _tailPos)
{
    tails.insert(tails.begin(), _tailPos);
}

void Snake::move()
{
    point oldPos = getPosition(); // get old postion
    SnakeDirection newDirection = getDirection(); // get direction
    switch (newDirection)
    {
        case UP:
                setPosition(oldPos.x, oldPos.y - 1);
                break;
        case DOWN:
                setPosition(oldPos.x, oldPos.y + 1);
                break;
        case LEFT:
                setPosition(oldPos.x - 1, oldPos.y);
                break;
        case RIGHT:
                setPosition(oldPos.x + 1, oldPos.y);
                break;
    }
}

vector<point> Snake::getTails(){
    return tails;
}

void Snake::popTails(){
    tails.pop_back();
}

void Snake::saveTails()
{
    insertTails(getPosition()); //insert current position into tails
    while (getTailLen() != getTails().size())
        popTails();
}
