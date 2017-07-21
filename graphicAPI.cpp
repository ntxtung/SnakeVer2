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

void showUnit(int x, int y)
{

    bar(x * unitLength , y * unitLength, x * unitLength + unitLength, y * unitLength + unitLength);


}
