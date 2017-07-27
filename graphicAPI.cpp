#ifndef DECLARATION_H_INCLUDED
    #include "Declaration.h"
#endif // DECLARATION_H_INCLUDED

#ifndef GRAPHICAPI_H_INCLUDED
    #include "GraphicAPI.h"
#endif // CONSOLEAPI_H_INCLUDED

void setup()
{
    initwindow(W, H);
    //initgraph(&gd, &gm, "BGI");
}
/**
    From GraphicAPI, put a FlatUnit to (x,y) block

     @param  X Position
     @param  Y Position
 */

void showUnit(int x, int y, int pattern, int color)
{
    setfillstyle(pattern,color);
    bar(x * unitLength + 1 , y * unitLength + 1 , x * unitLength + unitLength , y * unitLength + unitLength);

}

void cls()
{
    setfillstyle(1,BLACK);
    bar(5,5,playZoneW*unitLength-5,playZoneH*unitLength-5);
}
