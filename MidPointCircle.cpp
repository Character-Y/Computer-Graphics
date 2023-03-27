//
//  MidPointCircle.cpp
//  Homework
//
//  Created by Hongyu Chen on 2023/3/24.
//

#include "MidPointCircle.hpp"

void MidPointCircle(GLint xs, GLint ys, GLint radius, GLfloat *color, GLfloat ratio, GLfloat points_radii);

void Circle(GLint xs, GLint ys, GLint radius, GLfloat *color, float increment)
{
    if (color)
        glColor3f(color[0], color[1], color[2]);
    else
        glColor3f(1, 1, 1);
    
    for (float degree = 0; degree < 360; degree += increment)
        WritePixel(xs + radius * cos(degree * PI / 180), ys + radius * sin(degree * PI / 180));
}

void CirclePoints(int n, GLint xs, GLint ys, GLfloat x, GLfloat y, GLfloat *color, GLfloat points_radii)
{
    GLfloat coordinates[][2] = {
        {xs + x, ys + y}, {xs - x, ys + y}, {xs - x, ys - y}, {xs + x, ys - y},
        {xs + y, ys + x}, {xs - y, ys + x}, {xs - y, ys - x}, {xs + y, ys - x}};
    GLint radius = 5;
    
    if (points_radii)
        for (int i = 0; i < n; ++i)
            MidPointCircle(coordinates[i][0], coordinates[i][1], radius, color, points_radii / radius, 0);
    else
        for (int i = 0; i < n; ++i)
            WritePixel(coordinates[i][0], coordinates[i][1], color);
}

void MidPointCircle(GLint xs, GLint ys, GLint radius, GLfloat *color, GLfloat ratio, GLfloat points_radii)
{
    GLint x = 0;
    GLint y = radius;
    GLint d = 1 - radius;
    
    while (y > x)
    {
        CirclePoints(8, xs, ys, ratio * x, ratio * y, color, points_radii); // 画八分怎之一然后根据坐标画出其余部分
        if (d < 0) //选择 T
            d += 2 * x + 3;
        else { //选择 B
            d += 2 * (x - y) + 5;
            --y;
        }
        ++x;
    } //End of while
    if (x == y)
        CirclePoints(4, xs, ys, ratio * x, ratio * y, color, points_radii); // 对于线y=x+yr与圆交点画四个点就可以
}
  
void DrawMidPointCircle()
{
    GLint xs = 3, ys = 0, xe = 253, ye = 250; // 栅格的位置
    GLint spacing = 1; // 栅格间距
    
    int n = 5; // 画n个圆
    GLint x = xs + round(round((xe - xs) / spacing) / 2) * spacing, y = ys + round(round((ye - ys) / spacing) / 2) * spacing; // 栅格中心点作为圆心坐标
    GLint radii[n];
    for (int i = 0; i < n; ++i)
        radii[i] = (xe - xs < ye - ys ? xe - xs : ye - ys) / spacing / n / 2 * (i + 1); // 计算各个圆的半径
    for (int i = 0; i < n; ++i)
        printf("r%d=%d\n", i + 1, radii[i]);
    GLfloat color[][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {0, 1, 1}, {1, 1, 0}, {1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {0, 1, 1}, {1, 1, 0}};
    GLfloat ratio = spacing; // 放大、缩小比例，根据栅格间距大小映射
    GLfloat points_radii = 1; // 小圆点的半径
//    int NumOfPoints[] = {7 * 4, 14 * 4, 21 * 4, 28 * 4, 35 * 4};
    
    clock_t start, stop;
    
    DrawGrid(xs, ys, xe, ye, spacing, NULL); // 画栅格
    
    for (int i = 0; i < n; ++i)
    {
        start = clock();
        Circle(x, y, ratio * radii[i], color[i], 0.5);
        stop = clock();
        printf("Duation is %ld ticks.\n", stop - start);
        
        start = clock();
        MidPointCircle(x, y, radii[i], color[i], ratio, points_radii);
        stop = clock();
        printf("Duation is %ld ticks.\n\n", stop - start);
    }
}
