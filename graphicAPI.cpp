#include "Declaration.h"
#include "GraphicAPI.h"

void setup()
{
    initwindow(W, H, "THIS IS A SNAKE GAME!");
}

void drawBlock(int x, int y, fill_styles pattern, int color)
{
    setfillstyle(pattern, color);
    bar((x + scrX -1) * unitLength + 1 ,
        (y + scrY -1) * unitLength + 1 ,
        (x + scrX -1) * unitLength + unitLength ,
        (y + scrY -1) * unitLength + unitLength);
}

void drawImage(int x, int y)
{
    readimagefile();
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

