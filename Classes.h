#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include "Declaration.h"

#include <vector>
#include <windows.h>

using namespace std;

enum SnakeDirection {UP, DOWN, LEFT, RIGHT}; //{0, 1, 2, 3}

struct point
{
    int x, y;
};

class Snake
{
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
        int tailLen = 0; //length of Tails;
        vector<point> tails;
        SnakeDirection direction = RIGHT; //default direction

    protected:
};

class SnakeGame
{
public:
    void  setZone(int _x, int _y, int _val);
    void  setZone(point _pos, int _val);
    int   getZone(int _x, int _y);
    int   getZone(point _pos);
    int   getScore();

private:
    int zone[playZoneH+1][playZoneW+1] = { {0} };
    int score = 0;
    Snake snake;
    //~~
    int secureKey = GetTickCount();
    //~~ FUNCTION
    void  setScore(int _score);
};

#endif // CLASSES_H_INCLUDED
