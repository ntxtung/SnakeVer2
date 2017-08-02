#include <iostream>

#include "Declaration.h"
#include "GraphicAPI.h"

using namespace std;

/*
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

void gradientTest(bool isOn)
{
    if (isOn==true)
    {
        int b=0;
        int g=0;
        for (int i=0; i<=W; i+=W/255)
        {
            for (int j=0; j<=H; j+=H/255)
            {

                putpixel(i,j,RGB(i,g,b));
                g++;
            }
            b++;
        }

    }
}
*/
void develop()
{
    showInfo(1);
    showGrid(1);

    showCross(1);
    gradientTest(1);
}
