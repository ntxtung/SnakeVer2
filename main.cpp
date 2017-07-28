#include "Declaration.h"
#include "GraphicAPI.h"
#include "Develop.h"
#include "GamePlay.h"
#include "Screens.h"

//int gd = DETECT, gm;

//-------------------------//

int main()
{
    setup();
    develop();

    playScreen();

    getch();
    closegraph();
    return 0;
}
