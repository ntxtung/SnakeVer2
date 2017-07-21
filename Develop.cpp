#ifndef DECLARATION_H_INCLUDED
    #include "Declaration.h"
#endif // DECLARATION_H_INCLUDED

#ifndef GRAPHICAPI_H_INCLUDED
    #include "GraphicAPI.h"
#endif // CONSOLEAPI_H_INCLUDED


using namespace std;


void showCross(bool isOn)
{
    if (isOn==true)
    {
        setcolor(BLUE);
        line(0,0,W,H);
        line(W,0,0,H);
        setcolor(DEFAULT_COLOR);
    }

}

void showGrid(bool isOn)
{
    if (isOn==true)
    {
        setcolor(RED);
        for (int i=0; i<=W; i+=unitLength)
            line(i,0,i,H);
        for (int i=0; i<=H; i+=unitLength)
            line(0,i,W,i);
        setcolor(DEFAULT_COLOR);
    }
}

void showInfo(bool isOn)
{
    if (isOn==true)
    {
        cout << "IU Snake version " << endl;
        cout << "Resolution: " << W << " x " << H << endl;
        cout << "Unit length: " << unitLength << "(pixel)" << endl;

    }
}

void develop()
{
    showInfo(true);
    showGrid(true);
    showCross(false);
}
