#include "Screens.h"
#include "Classes.h"
#include "graphicAPI.h"

//#define DEBUG

#include <iostream>


int main()
{
    //ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false); // Dont open the console --> Just remove the comment when build the program
    //FreeConsole(); // The same with ShowWindow
    initGraphic();
    while (1)
    {
        mainMenu();
        SnakeGame *game = new SnakeGame();
        game->loadMap("map\\map1.txt");
        game->beginGame();
    }
    closegraph();
    return 0;
}
