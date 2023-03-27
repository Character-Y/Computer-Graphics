//
//  DDALine.cpp
//  Homework
//
//  Created by Hongyu Chen on 2023/3/22.
//

#include "DDALine.hpp"

void DDALine(GLfloat xs, GLfloat ys, //起点
             GLfloat xe, GLfloat ye, //终点
             GLfloat *color)
{
    GLint ix, iy, idx, idy;
    int Flag; //插补方向标记
    GLint Length; //插补长度
    GLfloat x, y, dx = xe - xs, dy = ye - ys;
    
    if (fabs(dy) < fabs(dx))
    { //X方向长 ， 斜率 <=1
        Length = abs(round(xe) - round(xs));
        Flag = 1; //最大的插补长度和方向标记
        ix = round(xs); //初始 X点
        idx = isign(dx); //X方向单位增量
        y = ys + dy / dx * ((float)ix - xs); //初始 Y点修正
        dy = dy / fabs(dx); //Y方向斜率增量
    }
    else
    { // Y方向长，斜率>1
        Length = abs(round(ye) - round(ys));
        Flag = 0;
        iy = round(ys); //初始 Y点
        idy = isign(dy); //Y方向单位增量
        x = xs + dx / dy * ((float)iy - ys); //初始 X点修正
        dx = dx / fabs(dy); //X方向斜率增量
    }
    
    if (Flag)
    { //X方向单位增量
        for (int n = 0; n <= Length; n++)
        {//X方向插补过程
            WritePixel(ix, round(y), color);
            ix += idx;
            y += dy;
        } //End of for
        
    } //End of if
    else
    { //Y方向斜率增量
        for (int n = 0; n <= Length; n++)
        {//Y方向插补过程
            WritePixel(round(x), iy, color);
            iy += idy;
            x += dx;
        } //End of for
        
    } //End of else
} //Finish

void DrawDDALine()
{
    for(int i = 0; i < 10; ++i)
        DDALine(25.0, 100.0, 225.0, 100.0 + i, 0);
}
