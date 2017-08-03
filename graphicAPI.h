#ifndef GRAPHICAPI_H_INCLUDED
#define GRAPHICAPI_H_INCLUDED

#include <graphics.h>

/**
Setup environment
*/
void initGraphic();

/**
Draw square block at (x,y)
    @param x
    @param y
    @param pattern See more fill_styles enum
*/
void drawBlock(int x, int y, fill_styles pattern, int color);

void drawImage(int left, int top, int right, int bottom, char *fileName);

void gradientStyle1 ();

#endif

/*
enum fill_styles
{
   EMPTY_FILL, // 0
   SOLID_FILL, // 1
   LINE_FILL,  // 2
   LTSLASH_FILL,
   SLASH_FILL,
   BKSLASH_FILL,
   LTBKSLASH_FILL,
   HATCH_FILL,
   XHATCH_FILL,
   INTERLEAVE_FILL,
   WIDE_DOT_FILL,
   CLOSE_DOT_FILL,
   USER_FILL
};
*/
