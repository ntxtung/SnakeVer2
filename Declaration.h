#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED

// CONSTANTS

#define KEY_UP      72
#define KEY_DOWN    80
#define KEY_LEFT    75
#define KEY_RIGHT   77
#define KEY_ENTER   13

#define ZONE_VOID 0
#define ZONE_WALL 1
#define ZONE_HEAD 2
#define ZONE_TAIL 3
#define ZONE_FOOD 4

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

///      SOUND              | FILENAME
 #define SOUND_START_SCREEN "soundtrack\\StartScreen.wav"
 #define SOUND_EAT          "soundtrack\\eat_sound.wav"
 #define SOUND_DEAD         "soundtrack\\hit_sound2.wav"
 #define SOUND_GAMEOVER     "soundtrack\\gameover.wav"
///      IMG                | FILENAME
 #define IMG_SNAKE1         "picture\\snake1.bmp"
 #define IMG_SNAKE2         "picture\\snake2.bmp"
 #define IMG_SNAKE3         "picture\\snake3.bmp"
 #define IMG_SNAKE4         "picture\\snake4.bmp"
 #define IMG_GAMEOVER       "picture\\Gameover.bmp"
///      TEXT               | TEXT
 #define TEXT_PRESSKEY      "[Press any key to start]"
 #define TEXT_COPYRIGHT     "Copyright by RIP_FINAL @ 2017"
 #define TEXT_MAJOR         "CSE IU - International University"
 ///      MAP FILE          | FILENAME
 #define MAP_TEMPLATE       "map\\template.txt"

/////////////////////////////////

#endif // DECLARATION_H_INCLUDED
