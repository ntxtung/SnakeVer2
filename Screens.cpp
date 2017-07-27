#ifndef DECLARATION_H_INCLUDED
    #include "Declaration.h"
#endif// DECLARATION_H_INCLUDED

#ifndef GRAPHICAPI_H_INCLUDED
    #include "GraphicAPI.h"
#endif // GRAPHICAPI_H_INCLUDED

#ifndef SOUND_H_INCLUDED
    #include "Sound.h"
#endif // SOUND_H_INCLUDED

#ifndef GAMEPLAY_H_INCLUDED
    #include "GamePlay.h"
#endif // GAMEPLAY_H_INCLUDED

#include "Screens.h"

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

extern bool gameOver;

void mainMenu()
{

}

void playScreen ()
{
    stopSound(); //turn off music
    cleardevice(); //clear menu screen
    while (1)
        draw();

    cout << " > GAME OVER\n";
}

void mapScreen()
{

}

void aboutScreen()
{

}

void resultScreen()
{

}

void selectMenu()
{

}


