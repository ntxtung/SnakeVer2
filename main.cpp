#include "GraphicAPI.h"
#include "Develop.h"
#include "Screens.h"

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
