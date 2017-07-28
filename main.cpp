#ifndef DECLARATION_H_INCLUDED
    #include "Declaration.h"
#endif // DECLARATION_H_INCLUDED

#ifndef GRAPHICAPI_H_INCLUDED
    #include "GraphicAPI.h"
#endif // GRAPHICAPI_H_INCLUDED

#ifndef DEVELOP_H_INCLUDED
    #include "Develop.h"
#endif // DEVELOP_H_INCLUDED

#ifndef GAMEPLAY_H_INCLUDED
    #include "GamePlay.h"
#endif // GAMEPLAY_H_INCLUDED

#ifndef SCREENS_H_INCLUDED
    #include "Screens.h"
#endif // SCREENS_H_INCLUDED

using namespace std;

//int gd = DETECT, gm;


//-------------------------//

int main()
{
    setup();
    develop();

    makePlayZone();
    for (int i=1; i<=playZoneW; i++)
        for (int j=1; j<=playZoneH; j++)
            showUnit(i,j,1,YELLOW);
    playScreen();



    getch();
    closegraph();
    return 0;
}
