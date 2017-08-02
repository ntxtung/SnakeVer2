#include "Classes.h" //included <vector>
#include "GraphicAPI.h"

using namespace std;

SnakeGame::SnakeGame()
{
    initGraphic();
}

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

/*void  SnakeGame::snakeMove()
{
    point currentPos = snake.getPosition();
    switch (snake.getDirection())
    {
    case UP:
        snake.setPosition(currentPos.x, currentPos.y - 1);
        break;
    case DOWN:
        snake.setPosition(currentPos.x, currentPos.y + 1);
        break;
    case LEFT:
        snake.setPosition(currentPos.x - 1, currentPos.y);
        break;
    case RIGHT:
        snake.setPosition(currentPos.x + 1, currentPos.y);
        break;
    }
}*/

void SnakeGame::drawScreen()
{
    for (int i=1; i<playZoneH; i++)
    {
        for (int j=1; j<playZoneW; j++)
         {
            switch (getZone(j, i)) // zone[i][j])
            {
                case 0: // None
                {
                    drawBlock(scrX + j -1, scrY + i-1, SOLID_FILL, BLACK);
                    break;
                }
                case 1: // Danger block
                {
                    drawBlock(scrX + j-1, scrY + i-1, SOLID_FILL, RED);
                    break;
                }
                case 2: // Head
                {
                    drawBlock(scrX + j-1, scrY + i-1, SOLID_FILL, RGB(0,155,155));
                    break;
                }
                case 3: // Tail
                {
                    drawBlock(scrX + j-1, scrY + i-1, SOLID_FILL, GREEN);
                    break;
                }
                case 4: // Food
                {
                    drawBlock(scrX + j-1, scrY + i-1, SOLID_FILL, BLUE);
                    break;
                }
                default: // None
                {
                    //drawBlock(scrX + j, scrY + i, SOLID_FILL, BLACK);
                }
            }
        }
    }
}
