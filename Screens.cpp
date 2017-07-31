#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>

#include "Declaration.h"
#include "GraphicAPI.h"
#include "Sound.h"
#include "GamePlay.h"
#include "Screens.h"

using namespace std;

extern bool gameOver;

void mainMenu()
{
    //gradientStyle1();
    playSound("soundtrack\\StartScreen.wav",1);

    int logoX=250;
    int logoY=50;
    int order=1;

    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(10,H-30,"Copyright by RIP_FINAL @ 2017");
    outtextxy(W-400,H-30,"CSE IU - International University");
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(470,500,"[Press any key to start]");

    while (!kbhit())
    {
        if (order%4+1 == 1)
            readimagefile("picture\\snake1.bmp",logoX, logoY, logoX + 312*2.5, logoY + 65*2.5);
        if (order%4+1 == 2)
            readimagefile("picture\\snake2.bmp",logoX, logoY, logoX + 312*2.5, logoY + 65*2.5);
        if (order%4+1 == 3)
            readimagefile("picture\\snake3.bmp",logoX, logoY, logoX + 312*2.5, logoY + 65*2.5);
        if (order%4+1 == 4)
            readimagefile("picture\\snake4.bmp",logoX, logoY, logoX + 312*2.5, logoY + 65*2.5);
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

//------------------------------
void gameOverScreen()
{
    gameOver = true;
    fflush(stdin);
    cleardevice();
    int logoX=400;
    int logoY=50;
   readimagefile("picture\\Gameover.bmp",logoX, logoY, logoX + 176*2.5, logoY + 85*2.5);

    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(470,500,"[Press any key to exit]");

    playSound("soundtrack\\gameover.wav",1);
    getch();

}
