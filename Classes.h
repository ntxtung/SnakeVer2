#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include "Declaration.h"

#include <vector>

using namespace std;

enum SnakeDirection {UP, DOWN, LEFT, RIGHT}; //{0, 1, 2, 3}

struct point{
    int x, y;
};

class Snake{
public:
    Snake(int _x, int _y);
    Snake(point _pos);
    ~Snake();
    void  setPosition(int _x, int _y);
    void  setPosition(point _pos);
    point getPosition();
    void  setTailLen(int _len);
    int   getTailLen();
    void  setDirection(SnakeDirection _direction, bool _antiReverse = true);
    SnakeDirection getDirection();
    void  insertTails(point _tailPos);
    vector<point>  getTails();
    void  popTails(); //NEED SET ZONE TO 0

    void  move();
    void  saveTails();

private:
    point pos;
    int   tailLen = 0; //length of Tails; .
    vector<point> tails;
    SnakeDirection direction = RIGHT; //default direction
};

class Food{
public:
    Food(int _x, int _y);
    Food(point _pos);
    ~Food();
    void  setPos(int _x, int _y);
    void  setPos(point _pos);
    point getPos();
    void  setColor(int _color);
    int   getColor();
private:
    point pos; //position
    int   color = 14; //YELLOW
};

class SnakeGame{
public:
    SnakeGame(); // construction
    ~SnakeGame(); //destruction
    void  setZone(int _x, int _y, int _val);
    void  setZone(point _pos, int _val);
    int   getZone(int _x, int _y);
    int   getZone(point _pos);
    int   getScore();
    int   setGameSpeed(int _gameSpeed);
    int   getGameSpeed();

    void  loadMap(char *_dir);
    void  beginGame();

private:
    bool  gameOver = true;
    Food  *food = new Food();
    int   zone[playZoneH+1][playZoneW+1] = { {0} };
    int   score = 0;
    int   gameSpeed = 80;
    Snake *snake = new Snake(playZoneW/2, playZoneH/2);
    //
    void  setSecureKey(int _val);
    //~~
    int   secureKey;
    //~~ FUNCTION
    void  setScore(int _score);
    void  setFoodPosition(point _pos);
    void  setFoodPosition(int _x, int _y);
    point getFoodPosition();
    void  getKey2ChangeDirection(); //getkey and auto change direction
    void  snakeMove(); //change position depending on direction
    void  drawPoint(int x, int y);
    void  drawScreen(); // draw Zone to GameScreen
    void  drawBorder(); // draw border
    void  drawScoreBoard(); // draw Scoreboard
    void  drawScoreValue(); // draw score in Scoreboard
    void  gameThread(); // main game thread
    void  logic();
    void  foodSpawn();
};

#endif // CLASSES_H_INCLUDED
