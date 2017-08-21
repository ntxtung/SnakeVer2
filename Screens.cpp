#include <iostream>
#include <stdio.h>

#include "Declaration.h"
#include "GraphicAPI.h"
#include "Sound.h"
#include "Screens.h"

using namespace std;

//extern bool gameOver;

void mainMenu()
{
   // initGraphic();
    playSound(SOUND_START_SCREEN, 1);

    int logoX = 250;
    int logoY = 50;
    int order = 1;
    settextjustify(LEFT_TEXT, BOTTOM_TEXT);
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(10,H-13, TEXT_COPYRIGHT);
    outtextxy(W-400,H-13, TEXT_MAJOR);
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(470,500, TEXT_PRESSKEY);

    while ( !kbhit() ) //PRESS KEY TO CONTINUE
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
}

//------------------------------
void gameOverScreen()
{
    //fflush(stdin);
    cleardevice(); //clear the screen
    int logoX=400;
    int logoY=50;

    readimagefile(IMG_GAMEOVER, logoX, logoY, logoX + 176*2.5, logoY + 85*2.5);

    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(620,500, TEXT_PRESSKEY);

    playSound(SOUND_GAMEOVER, 1);
    getch(); //wait key pressed
}
