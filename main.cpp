#include "GraphicAPI.h"
#include "Develop.h"
#include "Screens.h"
#include "Map.h"
#include "Classes.h"

#include <iostream>

using namespace std;

int main()
{
    //ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false); // Dont open the console --> Just remove the comment when build the program

    //makeTemplateMap();
    //loadMap1();
    //setup();        //setup environment

/*
    initGraphic();        //setup environment

    //develop();    //debug only
    mainMenu();     //show main menu

    getch();        // close gameover screen
    closegraph();   //free graphs

    //FreeConsole(); // The same with ShowWindow
*/
// TEST CLASSES
    Snake snake(10,20);

    cout << snake.getPosition().x << " - " << snake.getPosition().y << endl;
    cout << snake.getTailLen() << endl;
    cout << snake.getDirection() << endl;
    SnakeGame game;
    game.setZone(1,1,3);
    game.drawScreen();

    getch();
    closegraph();
    //snake.saveTails();
    return 0;
}
