#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED

// CONSTANTS

#define Debug   false

#define KEY_UP      72
#define KEY_DOWN    80
#define KEY_LEFT    75
#define KEY_RIGHT   77
#define KEY_ENTER   13

#define MAX_TAIL (W-2)*(H-2)

#define DEFAULT_COLOR WHITE

const int W = 1280;
const int H = (9*W)/16;
const int unitLength = W/40;
const int W_unit = W/unitLength;
const int H_unit = H/unitLength;

const int playZoneW = 30;
const int playZoneH = 20;

const int scrX = 1;    //Screen LeftTop X
const int scrY = 1;    //Screen LeftTop Y

///      SOUND      | FILENAME
 #define SOUND_MENU "soundtrack\\StartScreen.wav"
 #define SOUND_EAT  "soundtrack\\eat_sound.wav"
 #define SOUND_DEAD "soundtrack\\hit_sound2.wav"
/////////////////////////////////

//#include <winbgim.h>
//#include <dos.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//#include <conio.h> // Dont use this with the graphics.h
//#include <windows.h>
//#include <vector>
//#include <time.h>
//#include <string>

#endif // DECLARATION_H_INCLUDED
