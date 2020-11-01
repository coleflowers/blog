//
//  points.c
//
//  Created by 爱写代码的小马 on 2020/10/31.
//  Copyright © 2020 mll <coleflowersma at gmail dot com>. All rights reserved.
//  clang -framework OpenGL -framework GLUT points.c -o points

#include <stdio.h>
#include <GLUT/glut.h>

/**
 * 画些点
 */
void paintPoints()
{
    glViewport(400, 400, 400, 400);
    glPointSize(15);
    glBegin(GL_POINTS);
        glColor3f(1.f, 0.f, 0.f); // 红色
        glVertex2f(0.0, 0.0); // 中心位置
    
        glColor3f(0.f, 1.f, 0.f); // 绿色
        glVertex2f(.5, -.5); // 右下中心
        
        glColor3f(1.f, 0.5f, 0.f); // 橙色
        glVertex2f(-0.5, 0.5); // 左上中心
    glEnd();
}

/**
 * 根据心形线算法用点画心形
 * link: https://baike.so.com/doc/6758094-6972695.html
 * x=a*(2*cos(t)-cos(2*t))
 * y=a*(2*sin(t)-sin(2*t))
 */
void Cardioid1()
{
    glViewport(0, 400, 400, 400);
    glColor3f(252.f/255, 64.f/255, 66.f/255);
    glPointSize(3);
    glBegin(GL_POINTS);
        for (float t = 0; t < 2*3.14; t = t + 0.05)
        {
            if (t > 1)
            {
                // 换绿色
                glColor3f(.0, 1.0, .0);
            }
            int a = 3.1;
            float x = a * (2 * cos(t) - cos(2 * t));
            float y = a * (2 * sin(t) - sin(2 * t));
            // printf("x:%f y:%f\n", x, y);
            glVertex2f(x/9, y/9);
        }

    glEnd();
    glFlush();
}

/**
 * 算法参考： https://cloud.tencent.com/developer/article/1329640
 */
void Cardioid2() {
    glViewport(0, 0, 400, 400);
    glColor3f(255.0/255, 0.0/255, 94.0/255);

    float red = 120.0;
    float gree = 10.0;
    float blue = 74.0;
    float colorSpanRed = 10.f;
    float colorSpan = 5.f;

    glPointSize(6);
    glBegin(GL_POINTS);
        for (float y = 1.5f; y > -1.5f; y -= 0.1f) {
            for (float x = -1.5f; x < 1.5f; x += 0.05f) {
                float z = x * x + y * y - 1;
                float f = z * z * z - x * x * y * y * y;
                if (f <= 0.0f) {
                    int index = (int)(f * -8.0f);
                     
                    glColor3f((red+index*colorSpanRed)/255,
                        (gree+index*colorSpan)/255,
                        (blue+index*colorSpan)/255);

                    // printf("index : %d x:%f y:%f\n", index, x, y);
                    glVertex2f(x*10.f/15, y*10.f/15);
                }
                //putchar(f <= 0.0f ? ".:-=+*%@"[(int)(f * -8.0f)] : ' ');
            }
            //putchar(' ');
            //printf("\n");
        }
    glEnd();
}

/**
 * 使用点模拟虚线
 */
void paintDottedLine()
{
    glViewport(400, 0, 400, 400);
    glPointSize(4);
    glColor3f(0.f, 0.5f, 1.f); // 红色
    glBegin(GL_POINTS);
        // 用点模拟画一条虚线
        for (float i = -1; i<= 1; i+=0.04) {
            glVertex2f(i, 0.f); // 绿色
        }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    // 第一象限
    paintPoints();
    
    // 第二象限
    Cardioid1();
    
    // 第三象限
    Cardioid2();
    
    // 第四象限
    paintDottedLine();
    
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Cardioid by Coleflowers");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
