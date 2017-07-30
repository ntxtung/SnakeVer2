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
    //ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false); // Dont open the console --> Just remove the comment when build the program

    setup();
    develop();
    mainMenu();




    getch();
    closegraph();

    //FreeConsole(); // The same with ShowWindow
    return 0;
}
