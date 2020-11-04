#include <GLUT/glut.h>
#include <math.h>
#define PI 3.14159265

#include "util.h"

// author coleflowers
// clang -framework OpenGL -framework GLUT lines.c -o lines

// glEnable (GL_LINE_STIPPLE); // 启动虚线模式
// glDisable (GL_LINE_STIPPLE); // 关闭虚线模式

/**
 * 平面上一点x1,y1,绕平面上另一点x2,y2顺时针旋转θ角度 ，怎么求旋转后的x1,y1对应的坐标x，y
 *
 * 把角度当作弧度用
x=(x1-x2)cosθ-(y1-y2)sinθ+x2
y=(y1-y2)cosθ+(x1-x2)sinθ+y2
 */
void paintLines(int max, int gap)
{
    glLineWidth(2.0f);  
    glBegin(GL_LINES);  

        float x2 = 0;
        float y2 = 0;
        
        float startX = -1;
        float startY = 0;
        float endX = 1;
        float endY = 0;
        for (int i = 0; i <= max; i=i+gap)
        {
            float xa = (startX - x2) * cos(i) - (startY - y2) * sin(i) + x2;
            float ya = (startY - y2) * cos(i) + (startX - x2) * sin(i) + y2;

            float xb = (endX - x2) * cos(i) - (endY - y2) * sin(i) + x2;
            float yb = (endY - y2) * cos(i) + (endX - x2) * sin(i) + y2;

            // printf("xa:%f ya:%f\n", xa, ya);
            glVertex2f(xa, ya);
            glVertex2f(xb, yb);

            // startX = xa;
            // startY = ya;

            // endX = xb;
            // endY = yb;
        }

    glEnd();
}

/**
 * 顺时针旋转画直线
 * math.h中三角函数的参数是弧度，不是角度
 * 绕点旋转算法
 * x' = (x-a)cosα+(y-b)sinα+a
 * y' = -(x-a)sinα+(y-b)cosα+b
 * @param    maxAngle  最大角度
 * @param    gap       每次旋转角度
 */
void paintLines2(int maxAngle, int gap)
{
    glLineWidth(2.0f);  
    glBegin(GL_LINES);

        float x2 = 0;
        float y2 = 0;
        
        float startX = -1;
        float startY = 0;
        float endX = 1;
        float endY = 0;
        for (int i = 0; i <= maxAngle; i=i+gap)
        {
            float xa = (startX - x2) * cos(i*PI/180) + (startY - y2) * sin(i*PI/180) + x2;
            float ya = (startX - x2) * sin(i*PI/180) + (startY - y2) * cos(i*PI/180) + y2;

            float xb = (endX - x2) * cos(i*PI/180) + (endY - y2) * sin(i*PI/180) + x2;
            float yb = (endX - x2) * sin(i*PI/180) + (endY - y2) * cos(i*PI/180) + y2;

            glVertex2f(xa, ya);
            glVertex2f(xb, yb);
        }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    ////////////////////////////////
    /// 第一象限
    glViewport(800, 800, 800, 800);

    // 画一条实线
    glBegin(GL_LINES);  
        glVertex2f(0.1f, 0.1f);
        glVertex2f(0.8f, 0.8f);
        glVertex2f(0.3f, 0.5f);
    glEnd();

    // 虚线
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x4e73a); // 0xD903  0x0F0F
    glLineWidth(4.0f);  
    glBegin(GL_LINES);  
        glVertex2f(0.0f, 0.0f);
        glVertex2f(1.0f, 0.0f);
    glEnd();
    glDisable(GL_LINE_STIPPLE);

    ////////////////////////////////
    /// 第二象限
    // 连续的线段 跟上边的顶点一样，注意看细节
    glViewport(0, 800, 400, 400);
    glBegin(GL_LINE_STRIP);
        glVertex2f(0.5f, 1.0f);
        glVertex2f(0.8f, 0.3f);
        glVertex2f(0.1f, -0.9f);
        glVertex2f(-0.3f, 1.0f);
    glEnd();

    // 封闭的线段
    glViewport(0, 800, 800, 800);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.3f, 0.4f);
        glVertex2f(0.8f, 0.3f);
        glVertex2f(0.89f, 0.2f);
        glVertex2f(0.1f, -0.8f);
    glEnd();

    ////////////////////////////////
    // 第三象限
    // 画不同角度的线
    glViewport(0, 0, 800, 800);
    paintLines2(180, 9);

    ////////////////////////////////
    // 第四象限
    // 画不同角度的线
    glViewport(800, 0, 800, 800);
    paintLines(360, 2);

    glFlush();  //强制刷新缓冲，保证绘图命令被执行
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Lines by Coleflowers");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
