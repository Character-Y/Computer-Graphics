//
//  util.hpp
//  Homework
//
//  Created by Hongyu Chen on 2023/3/23.
//

#include <math.h>

#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

#ifndef util_hpp
#define util_hpp

#define PI 3.1415926535

int isign(double i);

void swap(int &a, int &b);

void WritePixel(GLfloat x, GLfloat y);
void WritePixel(GLfloat x, GLfloat y, GLfloat *color);

void DrawGrid(GLfloat xs, GLfloat ys, GLfloat xe, GLfloat ye, GLfloat spacing, GLfloat *color);

#endif /* util_hpp */
