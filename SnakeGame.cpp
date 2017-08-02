#include <fstream>
#include <iostream>
#include <windows.h>

#include "Classes.h" //included <vector>
#include "GraphicAPI.h"
#include "Sound.h"

using namespace std;

SnakeGame::SnakeGame(){
    initGraphic();
    srand(GetTickCount());
    this->setSecureKey(rand()%10 + 1);
}

SnakeGame::~SnakeGame(){
    closegraph();
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
    this->drawScoreValue();
}
void  SnakeGame::setSecureKey(int _val){
    this->secureKey = _val;
}

void  SnakeGame::snakeMove(){
    point currentPos = snake->getPosition();
    switch (snake->getDirection())
    {
    case UP:
        snake->setPosition(currentPos.x, currentPos.y - 1);
        break;
    case DOWN:
        snake->setPosition(currentPos.x, currentPos.y + 1);
        break;
    case LEFT:
        snake->setPosition(currentPos.x - 1, currentPos.y);
        break;
    case RIGHT:
        snake->setPosition(currentPos.x + 1, currentPos.y);
        break;
    }
}

void  SnakeGame::drawScreen(){
    for (int i=1; i<playZoneH; i++)
    {
        for (int j=1; j<playZoneW; j++)
        {
            switch (getZone(j, i)) // zone[i][j])
            {
            case 0: // None
                drawBlock(scrX + j -1, scrY + i-1, SOLID_FILL, BLACK);
                break;
            case 1: // Danger block
                drawBlock(scrX + j-1, scrY + i-1, SOLID_FILL, RED);
                break;
            case 2: // Head
                drawBlock(scrX + j-1, scrY + i-1, SOLID_FILL, RGB(0,155,155));
                break;
            case 3: // Tail
                drawBlock(scrX + j-1, scrY + i-1, SOLID_FILL, GREEN);
                break;
            case 4: // Food
                drawBlock(scrX + j-1, scrY + i-1, SOLID_FILL, BLUE);
                break;
            }
        }
    }
}

void  SnakeGame::drawBorder(){
    for (int i=0; i<5; i++)
        rectangle(scrX * unitLength - i,
                  scrY * unitLength - i,
                  (scrX + playZoneW -1 ) * unitLength + i,
                  (scrY + playZoneH -1 ) * unitLength + i);
}

void  SnakeGame::drawScoreBoard(){
    for (int i=0; i<5; i++)
        rectangle( (scrX + playZoneW + 1)  * unitLength - i,
                   (scrY + 0) * unitLength - i,
                   (scrX + playZoneW + 7 ) * unitLength + i,
                   (scrY + 2) * unitLength + i);
}

void  SnakeGame::drawScoreValue(){
    char Score_Str[7];

    sprintf(Score_Str,"%d", this->score);

    settextjustify(CENTER_TEXT, CENTER_TEXT);
    settextstyle(BOLD_FONT, HORIZ_DIR, 4);
    outtextxy((scrX + playZoneW + 3.6)  * unitLength + 10,
              (scrY + 1.2) * unitLength,
               Score_Str);
}

void  SnakeGame::loadMap(char *_dir){
    ifstream inFile;
    inFile.open(_dir);
    char ch;
    for (int r=0; r<playZoneH+1; r++)
    {
        for (int c=0; c<playZoneW+1; c++)
        {
            inFile >> ch;
            if (ch == '#' && ch != '\n')
                this->setZone(c, r, 1);
        }

    }
    inFile.close();
    #ifdef DEBUG
        for (int r=0; r<playZoneH+1; r++)
        {
            for (int c=0; c<playZoneW+1; c++)
            {
                cout << getZone(c,r);
            }
        cout << endl;
    }
    #endif // DEBUG
}

void  SnakeGame::beginGame(){
    stopSound();    //stop all sound
    cleardevice(); //remove screen
    this->drawBorder();
    this->drawScreen();
    this->drawScoreBoard();
    this->drawScoreValue();
    this->gameThread();
}

void  SnakeGame::gameThread(){

}
