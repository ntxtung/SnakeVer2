/*
------- SNAKE 2 ------ GRAPHICS.H VERSION -------
20/7/2017:
- Snake2 begin
- Build Graphic Windows
- Build some develop function: showGrid, showCross, showInfo

*/
#ifndef DECLARATION_H_INCLUDED
    #include "Declaration.h"
#endif // DECLARATION_H_INCLUDED

#ifndef GRAPHICAPI_H_INCLUDED
    #include "GraphicAPI.h"
#endif // CONSOLEAPI_H_INCLUDED

#ifndef DEVELOP_H_INCLUDED
    #include "Develop.h"
#endif // CONSOLEAPI_H_INCLUDED

using namespace std;

//int gd = DETECT, gm;



//-------------------------//







//-------------------------//

int main()
{
    setup();
    develop();

    getch();
    closegraph();
    return 0;
}
