#ifndef DECLARATION_H_INCLUDED
    #include "Declaration.h"
#endif // DECLARATION_H_INCLUDED

#ifndef GRAPHICAPI_H_INCLUDED
    #include "GraphicAPI.h"
#endif // CONSOLEAPI_H_INCLUDED

void setup()
{
    initwindow(W, H, "THIS IS A SNAKE GAME!");
    //initgraph(&gd, &gm, "BGI");
}
/**
    From GraphicAPI, put a FlatUnit to (x,y) block in play zone

     @param  X Position
     @param  Y Position
 */

void showUnit(int x, int y, int pattern, int color)
{
    setfillstyle(pattern,color);
    bar((x + scrX -1) * unitLength + 1 ,
        (y + scrY -1) * unitLength + 1 ,
        (x + scrX -1) * unitLength + unitLength ,
        (y + scrY -1) * unitLength + unitLength);

}

void gradientStyle1()
{
    int b=0;
    int g=0;
    for (int i=0; i<=W; i+=W/400)
    {
        for (int j=0; j<=H; j+=W/400)
        {

            putpixel(i,j,RGB(i,g,b));
            g++;
        }
        b++;
    }
}

