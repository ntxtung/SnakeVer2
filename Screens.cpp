#include <iostream>
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
    playSound(SOUND_START_SCREEN, 1);

    int logoX = 250;
    int logoY = 50;
    int order = 1;

    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(10,H-30, TEXT_COPYRIGHT);
    outtextxy(W-400,H-30, TEXT_MAJOR);
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(470,500, TEXT_PRESSKEY);

    while (!kbhit())
    {
        if (order%4+1 == 1)
            readimagefile(IMG_SNAKE1, logoX, logoY, logoX + 312*2.5, logoY + 65*2.5);
        if (order%4+1 == 2)
            readimagefile(IMG_SNAKE2, logoX, logoY, logoX + 312*2.5, logoY + 65*2.5);
        if (order%4+1 == 3)
            readimagefile(IMG_SNAKE3, logoX, logoY, logoX + 312*2.5, logoY + 65*2.5);
        if (order%4+1 == 4)
            readimagefile(IMG_SNAKE4, logoX, logoY, logoX + 312*2.5, logoY + 65*2.5);
        order++;
        Sleep(700);
    }

    //getch();
    playScreen();
}

void playScreen ()
{
    stopSound(); //turn off music
    cleardevice(); //clear menu screen
    init();
    while (!gameOver)
        draw();


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
  
    readimagefile(IMG_GAMEOVER, logoX, logoY, logoX + 176*2.5, logoY + 85*2.5);

    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(620,500,"[Press any key to exit]");

    playSound(SOUND_GAMEOVER, 1);
    getch();

}
