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
    //gradientStyle1();
    playSound("soundtrack\\StartScreen.wav",1);

    int logoX=230;
    int logoY=50;
    int order=1;

    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(10,H-30,"Copyright by RIP_FINAL @ 2017");
    while (!kbhit())
    {
        if (order%4+1 == 1)
            readimagefile("picture\\snake1.gif",logoX, logoY, logoX + 312*2.5, logoY + 65*2.5);
        if (order%4+1 == 2)
            readimagefile("picture\\snake2.gif",logoX, logoY, logoX + 312*2.5, logoY + 65*2.5);
        if (order%4+1 == 3)
            readimagefile("picture\\snake3.gif",logoX, logoY, logoX + 312*2.5, logoY + 65*2.5);
        if (order%4+1 == 4)
            readimagefile("picture\\snake4.gif",logoX, logoY, logoX + 312*2.5, logoY + 65*2.5);
        order++;
        Sleep(700);
    }



    getch();
    playScreen();
}

void playScreen ()
{
    stopSound(); //turn off music
    cleardevice(); //clear menu screen
    init();
    while (!gameOver)
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


