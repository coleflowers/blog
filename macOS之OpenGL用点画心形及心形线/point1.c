#include <GLUT/glut.h>

// author coleflowers
// clang -framework OpenGL -framework GLUT point1.c -o point1

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, 400, 400);
    glPointSize(15);
    glColor3f(1.f, 0.f, 0.f); // 红色
    glBegin(GL_POINTS);
        glVertex2f(0.0, 0.0); // 中心位置
    glEnd();

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(200, 200);
    glutCreateWindow("HelloWorld");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}