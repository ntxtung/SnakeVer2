#include "Classes.h" //included <vector>
#include "Declaration.h"

#include <stdlib.h>

using namespace std;

Snake::Snake(int _x, int _y){
    this->setPosition(_x, _y);
}

Snake::Snake(point _pos){
    this->setPosition(_pos);
}

Snake::~Snake() {}

void Snake::setPosition(int _x, int _y){
    this->pos.x = _x;
    this->pos.y = _y;
}

void Snake::setPosition(point _pos){
    this->pos = _pos;
}

point Snake::getPosition(){
    return this->pos;
}

void Snake::setTailLen(int _len){
    this->tailLen = _len;
}

int Snake::getTailLen(){
    return this->tailLen;
}

void Snake::setDirection(SnakeDirection _direction, bool _antiReverse)
{
    SnakeDirection oldDir = this->getDirection();
    if (_antiReverse)
    {
        if ((oldDir == LEFT && _direction != RIGHT) ||
            (oldDir == RIGHT && _direction != LEFT) ||
            (oldDir == UP && _direction != DOWN)    ||
            (oldDir == DOWN && _direction != UP))
                this->direction = _direction;
    }
    else
        this->direction = _direction;
}

SnakeDirection Snake::getDirection(){
    return this->direction;
}

void Snake::insertTails(point _tailPos)
{
    this->tails.insert(tails.begin(), _tailPos);
}

void Snake::move()
{
    point oldPos = this->getPosition(); // get old postion
    point newPos;
    SnakeDirection newDirection = this->getDirection(); // get direction
    switch (newDirection)
    {
        case UP:
                newPos.x = oldPos.x;
                newPos.y = oldPos.y - 1;
                break;
        case DOWN:
                newPos.x = oldPos.x;
                newPos.y = oldPos.y + 1;
                break;
        case LEFT:
                newPos.x = oldPos.x - 1;
                newPos.y = oldPos.y;
                break;
        case RIGHT:
                newPos.x = oldPos.x + 1;
                newPos.y = oldPos.y;
                break;
    }
    if (newPos.x == 0)
        newPos.x = playZoneW - 1;
    if (newPos.y == 0)
        newPos.y = playZoneH - 1;
    if (newPos.x == playZoneW)
        newPos.x = 1;
    if (newPos.y == playZoneH)
        newPos.y = 1;
    this->setPosition(newPos);
}

vector<point> Snake::getTails(){
    return this->tails;
}

void Snake::popTails(){
    this->tails.pop_back();
}

void Snake::saveTails()
{
    this->insertTails(getPosition()); //insert current position into tails
    while (this->getTailLen() != this->getTails().size())
        this->popTails();
}
