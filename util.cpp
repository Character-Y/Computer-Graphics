//
//  util.cpp
//  Homework
//
//  Created by Hongyu Chen on 2023/3/23.
//

#include "util.hpp"

int isign(double i)
{
    if (i)
        return (int)(i / fabs(i));
    else
        return (int)i;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void WritePixel(GLfloat x, GLfloat y)
{
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    
    glFlush();
}

void WritePixel(GLfloat x, GLfloat y, GLfloat *color)
{
    if (color)
        glColor3f(color[0], color[1], color[2]);
    else
        glColor3f(1, 1, 1);
    
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    
    glFlush();
}

void DrawGrid(GLfloat xs, GLfloat ys, GLfloat xe, GLfloat ye, GLfloat spacing, GLfloat *color)
{
    if (color)
        glColor3f(color[0], color[1], color[2]);
    else
        glColor3f(0.25, 0.25, 0.25);
    
    for (GLfloat i = 0; i <= ye - ys; i += spacing) {
        glBegin(GL_LINES);
            glVertex2f(xs, ys + i);
            glVertex2f(xe, ys + i);
        glEnd();
        
        glFlush();
    }
    for (GLfloat i = 0; i <= xe - xs; i += spacing) {
        glBegin(GL_LINES);
            glVertex2f(xs + i, ys);
            glVertex2f(xs + i, ye);
        glEnd();
        
        glFlush();
    }
}
