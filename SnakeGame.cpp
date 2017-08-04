#include <fstream>
#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Classes.h" //included <vector>
#include "GraphicAPI.h"
#include "Sound.h"
#include "Screens.h"

using namespace std;

SnakeGame::SnakeGame(){
    //initGraphic();
    srand(GetTickCount());
    this->setSecureKey(rand()%10 + 1);
}

SnakeGame::~SnakeGame(){
    gameOverScreen();
    //closegraph();
}

inline void  SnakeGame::setZone(int _x, int _y, int _val){
    this->zone[_y][_x] = _val;
    if ( !this->gameOver )
        this->drawPoint(_x, _y);
}
inline void  SnakeGame::setZone(point _pos, int _val){
    this->zone[_pos.y][_pos.x] = _val;
    if ( !this->gameOver )
        this->drawPoint(_pos.x, _pos.y);
}
inline int   SnakeGame::getZone(int _x, int _y){
    return this->zone[_y][_x];
}
inline int   SnakeGame::getZone(point _pos){
    return this->zone[_pos.y][_pos.x];
}
int   SnakeGame::getScore(){
    return this->score;
}
void  SnakeGame::setScore(int _score){
    this->score = _score;
    this->drawScoreValue();
}
void  SnakeGame::setSecureKey(int _val){
    this->secureKey = _val;
}
int   SnakeGame::setGameSpeed(int _gameSpeed){
    if (_gameSpeed>=20 && _gameSpeed<=150)
        this->gameSpeed = _gameSpeed;
}
int   SnakeGame::getGameSpeed(){
    return this->gameSpeed;
}

void  SnakeGame::getKey2ChangeDirection(){
    SnakeDirection _snakeDirection = this->snake->getDirection();
    if (kbhit()) //Keyboard Hit
    {
        int kbKey = getch();
        switch (kbKey)
        {
        case 'a':
        case 'A':
            _snakeDirection = LEFT;
            break;
        case 's':
        case 'S':
            _snakeDirection = DOWN;
            break;
        case 'd':
        case 'D':
            _snakeDirection = RIGHT;
            break;
        case 'w':
        case 'W':
            _snakeDirection = UP;
            break;
        case ',':
            this->setGameSpeed(this->getGameSpeed()+10);
            break;
        case '.':
            this->setGameSpeed(this->getGameSpeed()-10);
            break;
        }
        if (kbKey == 0 || kbKey == 224)
        {
            char tempKB = getch();
            switch (tempKB)
            {
            case KEY_LEFT:
                _snakeDirection = LEFT;
                break;
            case KEY_DOWN:
                _snakeDirection = DOWN;
                break;
            case KEY_RIGHT:
                _snakeDirection = RIGHT;
                break;
            case KEY_UP:
                _snakeDirection = UP;
                break;
            }
        }
        this->snake->setDirection(_snakeDirection);
    }
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
        for (int j=1; j<playZoneW; j++)
            this->drawPoint(j,i);
}

void  SnakeGame::drawPoint(int x, int y){
    switch (this->getZone(x, y)) // zone[i][j])
    {
    case ZONE_VOID: // None
        drawBlock(scrX + x -1, scrY + y-1, SOLID_FILL, BLACK);
        break;
    case ZONE_WALL: // Danger block
        drawBlock(scrX + x-1, scrY + y-1, SOLID_FILL, RED);
        break;
    case ZONE_HEAD: // Head
        drawBlock(scrX + x-1, scrY + y-1, SOLID_FILL, RGB(0,155,155));
        break;
    case ZONE_TAIL: // Tail
        drawBlock(scrX + x-1, scrY + y-1, SOLID_FILL, GREEN);
        break;
    case ZONE_FOOD: // Food
        drawBlock(scrX + x-1, scrY + y-1, SOLID_FILL, YELLOW);
        break;
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
    cleardevice();
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    settextstyle(BOLD_FONT, HORIZ_DIR, 6);
    getch();
    outtextxy(W/2, H/2 - 170,"INSTRUCTION");
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
    outtextxy(W/2, H/2 - 50, "THIS  IS  A  VERY  SIMPLE  GAME");
    outtextxy(W/2, H/2 - 0,  "EAT  EVERYTHING");
    outtextxy(W/2, H/2 + 50, "EXCEPT  ITS  TAIL");
    outtextxy(W/2, H/2 + 100,"AND  THE  WALL");
    getch();
    cleardevice();
    outtextxy(W/2, H/2 - 100,"USE");
    outtextxy(W/2, H/2 - 50, "W,  A,  S,  D");
    outtextxy(W/2, H/2 - 0,  "OR");
    outtextxy(W/2, H/2 + 50, "UP,  DOWN,  LEFT,  RIGHT");
    outtextxy(W/2, H/2 + 100,"TO  CONTROL  THE  HUNGRY  SNAKE");
    outtextxy(W/2, H/2 + 150,"PRESS  <  OR  >  TO  CHANGE  GAME  SPEED");
    getch();
    cleardevice();
    outtextxy(W/2, H/2 - 0,  "THE GAME BEGIN");
    Sleep(1000);
    stopSound();    //stop all sound
    playSound("soundtrack\\Despacito.wav",1);
    cleardevice(); //remove screen
    this->drawBorder();
    this->drawScreen();
    this->drawScoreBoard();
    this->drawScoreValue();
    this->gameOver = false;
    this->foodSpawn(); // first food spawn
    this->gameThread();
    //game over
    delete this;
}

void  SnakeGame::gameThread(){
    while (!gameOver)
    {
        this->getKey2ChangeDirection();
        point oldPos = this->snake->getPosition();

        this->snake->move(); // move head to other position

        this->logic();

        this->saveTail(oldPos);
        this->setZone(this->snake->getPosition(), ZONE_HEAD); // make new head in Zone

        this->makeTail();

        delay(this->getGameSpeed()); // delay each of game frame
    }
}

void  SnakeGame::logic(){
    point _pos = this->snake->getPosition();
    int zoneStatus = this->getZone(_pos);
    if (zoneStatus == ZONE_FOOD) //EAT FOOD
    {
        this->setScore(this->getScore() + 10);
        this->foodSpawn();
        this->snake->setTailLen(this->snake->getTailLen()+1);
    }
    else
    if (zoneStatus == ZONE_WALL || zoneStatus == ZONE_TAIL)
    {
        this->gameOver = true;
        playSound("soundtrack\\hit_sound2.wav");
        //Dead effect
        cleardevice();

        Sleep(100);
        this -> drawScreen();
        this -> drawBorder();
        Sleep(300);


        cleardevice();
        Sleep(100);
        this -> drawScreen();
        this -> drawBorder();
        Sleep(300);

        cleardevice();

        //
        Sleep(1000);
    }

}

void  SnakeGame::foodSpawn(){
    point _snakePos = this->snake->getPosition();
    point _foodPos;
    do
    {
        srand(_snakePos.x + _snakePos.y + _foodPos.x + _foodPos.y + GetTickCount()); //random seed {updated by HTML 31/7/17}
        _foodPos.x = 1 + rand() % (playZoneW-1);
        _foodPos.y = 1 + rand() % (playZoneH-1);
    }
    while ( this->getZone(_foodPos) != 0); // || (foodX==snakeX && foodY==snakeY));
    this->setZone(_foodPos, ZONE_FOOD);
}

void  SnakeGame::saveTail(point newTail){
    this->snake->tails.insert(this->snake->tails.begin(), newTail);
    //deleteTail
    while (this->snake->tails.size() > this->snake->getTailLen())
    {
        vector<point> snakeTails = this->snake->getTails();
        this->setZone(snakeTails[snakeTails.size()-1], ZONE_VOID);
        this->snake->popTails();
    }
}

void  SnakeGame::makeTail(){
    for (int i=0; i < this->snake->tails.size(); i++)
        this->setZone(this->snake->tails[i], ZONE_TAIL);
}
