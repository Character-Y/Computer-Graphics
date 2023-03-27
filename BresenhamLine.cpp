//
//  BresenhamLine.cpp
//  Homework
//
//  Created by Hongyu Chen on 2023/3/22.
//

#include "BresenhamLine.hpp"

void BresenhamLine(GLint xs, GLint ys, GLint xe, GLint ye, GLfloat *color)
{
    GLint x = xs, y = ys, dx = abs(xe - xs), dy = abs(ye - ys), sx = isign(xe - xs), sy = isign(ye - ys);
    //Swap ∆ x and ∆ y depending on the slope of the line.
    int Flag;
    if (dy > dx)
    {
        swap(dx, dy);
        Flag = 1;
    }
    else
        Flag = 0;
    //initialize the error term to compensate for a nonzero intercept
    GLint NError = 2 * dy - dx;
    //begin the main loop
    for (int i = 1; i <= dx; ++i)
    {
        WritePixel(x, y, color);
        if (NError >= 0)
        {
            if (Flag)
                x += sx;
            else
                y += sy;
            NError = NError - 2 * dx;
        }
        if (Flag)
            y += sy;
        else
            x += sx;
        NError = NError + 2 * dy;
    }//finish
}

void DrawBresenhamLine()
{
    BresenhamLine(125, 125, 300, 250, NULL);
    BresenhamLine(125, 125, 275, 275, NULL);
}

void DrawBresenhamLines()
{
    int i = 0;
    GLfloat color[8][3] = {{0.25, 0.25, 0.25}, {0, 0, 1}, {0, 1, 0}, {0, 1, 1}, {1, 0, 0}, {0.98, 0.04, 0.7}, {1, 1, 0}, {1, 1, 1}};
    GLfloat radius = 100;
    
    for (float degree = 0, n = 0; degree < 360; degree += 5, ++n) {
        if (n > 8) {
            ++i;
            n = 0;
        }
        BresenhamLine(125, 125, 125 + round(radius * cos(degree * PI / 180)), 125 + round(radius * sin(degree * PI / 180)), color[i]);
    }
}
