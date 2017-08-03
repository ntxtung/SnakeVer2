#include "GraphicAPI.h"
#include "Develop.h"
#include "Screens.h"
#include "Map.h"
#include "Classes.h"

//#define DEBUG

#include <iostream>

using namespace std;

int main()
{
    //ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false); // Dont open the console --> Just remove the comment when build the program
    //FreeConsole(); // The same with ShowWindow
    mainMenu();
    SnakeGame *game = new SnakeGame();
    game->loadMap("map\\map1.txt");
    game->beginGame();
    getch();
    return 0;
}
