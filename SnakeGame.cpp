#include "Classes.h" //included <vector>

using namespace std;

void  SnakeGame::setZone(int _x, int _y, int _val){
    zone[_y][_x] = _val;
}
void  SnakeGame::setZone(point _pos, int _val){
    zone[_pos.y][_pos.x] = _val;
}
int   SnakeGame::getZone(int _x, int _y){
    return zone[_y][_x];
}
int   SnakeGame::getZone(point _pos){
    return zone[_pos.y][_pos.x];
}
int   SnakeGame::getScore(){
    return score;
}

void  SnakeGame::setScore(int _score){
    score += _score;
}
