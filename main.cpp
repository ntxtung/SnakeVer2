#include "Screens.h"
#include "Classes.h"
#include "graphicAPI.h"

//#define DEBUG

#include <iostream>
#include <time.h>

#define release false

int main()
{
    if (release)
        ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false); // Dont open the console --> Just remove the comment when build the program

    initGraphic();
    while (1)
    {
        mainMenu();
        SnakeGame *game = new SnakeGame();
        int randomMap;

        srand(GetTickCount());
        randomMap = rand() % 7 + 1;

        switch (randomMap)
        {
        case 1:
            game->loadMap("map\\map1.txt");
            break;
        case 2:
            game->loadMap("map\\map2.txt");
            break;
        case 3:
            game->loadMap("map\\map3.txt");
            break;
        case 4:
            game->loadMap("map\\map4.txt");
            break;
        case 5:
            game->loadMap("map\\map5.txt");
            break;
        case 6:
            game->loadMap("map\\map6.txt");
            break;
        case 7:
            game->loadMap("map\\map7.txt");
            break;
        default:
            game->loadMap("map\\map0.txt");
            break;
        }

        game->beginGame();
        cleardevice();
    }
    closegraph();

    if (release)
        FreeConsole(); // The same with ShowWindow
    return 0;
}
