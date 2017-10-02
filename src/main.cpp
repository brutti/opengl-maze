#include <GL/freeglut.h>
#include <cstdio>
#include <cmath>
#include "robot.h"
#include "utils.h"

#define WIDTH 800
#define HEIGHT 600

Robot r;

void Init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // Habilita o z-buffer
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

void onDisplay() {
    // Seleciona a matriz de MODELVIEW
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gluLookAt(0.0, 0.0, -50.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    r.Draw();

    glutSwapBuffers();
}

void onResize(GLsizei w, GLsizei h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);

    // Inicializa o sistema de coordernadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, w/h, 2, 100);
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
        glutInitWindowSize(WIDTH, HEIGHT);
        glutInitWindowPosition(20, 20);
        glutCreateWindow("Maze");
        glutDisplayFunc(onDisplay);
        glutReshapeFunc(onResize);
        Init();
    glutMainLoop();
}