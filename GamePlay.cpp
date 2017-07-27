#ifndef DECLARATION_H_INCLUDED
    #include "Declaration.h"
#endif // DECLARATION_H_INCLUDED

#ifndef GRAPHICAPI_H_INCLUDED
    #include "GraphicAPI.h"
#endif // GRAPHICAPI_H_INCLUDED

#ifndef DEVELOP_H_INCLUDED
    #include "Develop.h"
#endif // DEVELOP_H_INCLUDED

using namespace std;

//int screen[playZoneH][playZoneW] = {};
int zone[playZoneH][playZoneW] = {0};
// Zone 0 = void
// Zone 1 = die
// Zone 2 = snakeHead
// Zone 3 = snakeTail
// Zone 4 = food

int score = 0, snakeX = (playZoneW/2), snakeY = (playZoneH/2), foodX = 0, foodY = 0, gameSpeed = 30, timer = 0;
int numTails = 1;

vector <int> tailX, tailY;

char direct ='S';
bool gameOver = false;
bool gameStart = false;

//------------------------------
void getKey()
{
    char tempDir = ' ';
    if (kbhit()) //Keyboard Hit
    {
        int kbKey = getch();
        if (kbKey == 'A' || kbKey == 'a')
            tempDir = 'L';
        else
        if (kbKey == 'S' || kbKey == 's')
            tempDir = 'D';
        else
        if (kbKey == 'D' || kbKey == 'd')
            tempDir = 'R';
        else
        if (kbKey == 'W' || kbKey == 'w')
            tempDir = 'U';
        else
        if (kbKey == 0 || kbKey == 224)
        {
            char tempKB = getch();
            switch (tempKB)
            {
                case KEY_LEFT:
                    tempDir = 'L';
                    break;
                case KEY_DOWN:
                    tempDir = 'D';
                    break;
                case KEY_RIGHT:
                    tempDir = 'R';
                    break;
                case KEY_UP:
                    tempDir = 'U';
                    break;
            }

        }

        if (tempDir != ' ' && gameStart == false)
        {
            gameStart = true;
        }
    }

    if (
        (tempDir=='D' && direct!='U') ||
        (tempDir=='U' && direct!='D') ||
        (tempDir=='L' && direct!='R') ||
        (tempDir=='R' && direct!='L')
        )
    direct=tempDir;
    //cout << direct;
}

void snakeMove()
{
    switch (direct)
        {
        case 'L':
            snakeX--;
            break;
        case 'R':
            snakeX++;
            break;
        case 'U':
            snakeY--;
            break;
        case 'D':
            snakeY++;
            break;
        }
}
//Make snake
void saveTail ()
{
    tailX.insert(tailX.begin(),snakeX);
    tailY.insert(tailY.begin(),snakeY);
    //deleteTail
    while (tailX.size()>numTails || tailY.size()>numTails)
    {
        zone[tailY[tailY.size()-1]][tailX[tailX.size()-1]] = 0;
        tailX.pop_back();
        tailY.pop_back();
    }
}

void makeSnake()
{
    zone[snakeY][snakeX] = 2;
}
void deleteSnake()
{
    zone[snakeY][snakeX] = 0;
}
//Food Spawn
void foodSpawn()
{
    do
    {
        srand(snakeX + snakeY + numTails + time(NULL)); //random seed
        foodX = 1 + rand() % W;
        foodY = 1 + rand() % H;
    }
    while (zone[foodY][foodX] !=0 || (foodX==snakeX && foodY==snakeY));
    zone[foodY][foodX]=4;
}
//---------------------------------
void makePlayZone()
{
    for (int i=0; i<=5; i++)
        rectangle(scrX * unitLength - i, scrY * unitLength - i, playZoneW * unitLength + i, playZoneH * unitLength + i);
}
//--------------------------------
void drawScreen()
{
    for (int i=0; i<=playZoneH; i++)
    {

        for (int j=0; j<=playZoneW; j++)
         {
            switch (zone[i][j])
            {
                case 0: // None
                {
                    showUnit(scrX + j, scrY + i, 1, BLACK);
                    break;
                }
                case 1: // Danger block
                {
                    showUnit(scrX + j, scrY + i, 1, RED);
                    break;
                }
                case 2: // Head
                {
                    showUnit(scrX + j, scrY + i, 1, GREEN);
                    break;
                }
                case 3: // Tail
                {
                    showUnit(scrX + j, scrY + i, 1, GREEN);
                    break;
                }
                case 4: // Food
                {
                    showUnit(scrX + j, scrY + i, 1, BLUE);
                    break;
                }
                default: // None
                {
                    showUnit(scrX + j, scrY + i, 1, BLACK);
                }
            }
        }
    }
}
//--------------------------------
void draw()
{
    makePlayZone();
    getKey();
    develop();
    if (1)
    {
        snakeMove();
        makeSnake();
        drawScreen();
        deleteSnake();
        Sleep(40);
    }
}
