//
//  main.cpp
//  Homework
//
//  Created by Hongyu Chen on 2023/3/20.
//

#include <stdio.h>
#include "DDALine.hpp"
#include "BresenhamLine.hpp"
#include "MidPointCircle.hpp"

void ChangeSize(int width, int height)
{
    if (!height)
        height = 1;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, width, height);
    if (width <= height)
        glOrtho(0.0f, 250.0f, 0.0f, 250.0f * height / width, 1.0f, -1.0f);
    else
        glOrtho(0.0f, 250.0f * width / height, 0.0f, 250.0f, 1.0f, -1.0f);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1000, 1500);
    glutCreateWindow("MidPointCircle");

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glutDisplayFunc(DrawMidPointCircle);
    glutReshapeFunc(ChangeSize);

    glutMainLoop();
    
    return 0;
}
