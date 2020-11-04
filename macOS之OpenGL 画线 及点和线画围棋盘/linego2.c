#include <GLUT/glut.h>
#include "util.h"

// 用 点 和 直线 模拟围棋盘
// author coleflowers
// clang -framework OpenGL -framework GLUT linego2.c util.c -o linego2

static float size = 1200;

// 围棋盘
void paintGrid()
{
    glViewport(0, 0, size, size);
    float margin = 80;
    glLineWidth(2.0f);
    glEnable(GL_POINT_SMOOTH); // 开启抗锯齿，否则画的点比较大的时候显示的方形
    glColor3fv(colorV("#000000"));
    glBegin(GL_LINES);
        int count = 18;
        float width = (2*size - 2 * margin) / count;
        float marginF = margin / size;
        for (int i = 0; i <= count; ++i)
        {
            float x1 = -1.f + marginF;
            float y1 = ((i * width) - size) / size + marginF;
            float x2 = 1.f - marginF;
            float y2 = ((i * width) - size) / size + marginF;
            // printf("%f %f %f %f\n", x1, y1, x2, y2);
            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
        }
        for (int i = 0; i <= count; ++i)
        {
            float y1 = -1.f + marginF;
            float x1 = ((i * width) - size) / size + marginF;
            float y2 = 1.f - marginF;
            float x2 = ((i * width) - size) / size + marginF;
            // printf("%f %f %f %f\n", x1, y1, x2, y2);
            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
        }
    glEnd();

    // 用点 画 目
    glPointSize(18);
    glBegin(GL_POINTS);
    glColor3fv(colorV("#000000"));
        for (int i = 0; i <= count; ++i)
        {
            for (int j = 0; j <= count; ++j)
            {
                if ((i == 3 || i == 9 || i == 15) 
                    && (j == 3 || j == 9 || j == 15))
                {
                    float x1 = ((i * width) - size) / size + marginF;
                    float y1 = ((j * width) - size) / size + marginF;
                    glVertex2f(x1, y1); // 右下中心
                }
            }
        }
    glEnd();
}

void display()
{
    // printf("%s\n", __FUNCTION__);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // glut方法，非OpenGL API
    int W = glutGet(GLUT_SCREEN_WIDTH);
    int H = glutGet(GLUT_SCREEN_HEIGHT);

    // 画背景
    glColor3fv(colorV("#D3A54A"));
    glViewport(0, 0, W*2, H*2); // 按照满屏计算，不再做单独的判断
    glRectf(-1.f, -1.f, 1.f, 1.f);

    paintGrid();

    glFlush();  //强制刷新缓冲，保证绘图命令被执行

    glutSwapBuffers();
}

void reshape(int width, int height) 
{
    // printf("%s w:%d h:%d\n", __FUNCTION__, width, height);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    size = min(width*2, height*2);
}

void idle(void)
{
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize((int)size/2, (int)size/2);
    glutCreateWindow("围棋盘 by Coleflowers");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutMainLoop();

    return 0;
}
