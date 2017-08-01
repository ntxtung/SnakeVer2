#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include <vector>

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

#endif // CLASSES_H_INCLUDED
