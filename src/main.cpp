#include <GL/freeglut.h>
#include <cstdio>
#include <cmath>
#include "robot.h"
#include "maze.h"
#include "utils.h"
#include "camera.h"

#define WIDTH 800
#define HEIGHT 600

Camera cam;
Maze m;
Robot r;

// angle of rotation for the camera direction
float angle=0.0;
// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f;

float fraction = 1.0f;
float rot = .0;

void Init() {
    // Posição incial do robo
    r.x = VIEW_SIZE - 145;
    r.y = 4.0f;
    r.z = VIEW_SIZE - 30;

    // Inicialização da camera
    cam.z = 600.0f;
    cam.type = TOPDOWN_CAM;

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    // Habilita o z-buffer
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

void onDisplay() {
    // Seleciona a matriz de MODELVIEW
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(cam.type == TOPDOWN_CAM)
        gluLookAt(VIEW_SIZE/2, cam.z, 600.0 , VIEW_SIZE/2, 10.0, VIEW_SIZE/2, 0.0, 1.0, 0.0);
    else if(cam.type == FOCUSED_CAM)
        gluLookAt(r.x - (WALL_SIZE*2) * sin(angle), 80.0f, r.z + (WALL_SIZE*2) * cos(angle), r.x + lx, 20.0, r.z + lz, 0.0, 1.0, 0.0);

    // Desenha o chão
    m.renderScene();

    glPushMatrix();
        m.renderMaze();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(r.x, r.y, r.z);
        glRotatef(rot, 0.0f, 1.0f, 0.0f);
        glScalef(1.5f, 1.5f, 1.5f);
        r.Draw();
    glPopMatrix();

    glutSwapBuffers();
}

void onResize(GLsizei w, GLsizei h) {
    if (h == 0) h = 1;
    float ratio = w * 1.0 / h;
    glViewport(0, 0, w, h);

    // Inicializa o sistema de coordernadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, ratio, 1, 2000);
}

void onPressKey(unsigned char key, int x, int y) {
    switch (key) {
        case '-':
            cam.z -= 10;
            break;
        case '+':
            cam.z += 10;
            break;
    }
    glutPostRedisplay();
}

void onPressKeySp(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            r.x += lx * fraction;
            r.z += lz * fraction;
            break;
        case GLUT_KEY_DOWN:
            r.x -= lx * fraction;
            r.z -= lz * fraction;
            break;
        case GLUT_KEY_RIGHT:
            angle += 1.5f;
            lx = sin(angle);
            lz = -cos(angle);
            rot += 90.0f;
            break;
        case GLUT_KEY_LEFT:
            angle -= 1.5f;
            lx = sin(angle);
            lz = -cos(angle);
            rot -= 90.0f;
            break;
        case GLUT_KEY_F1:
            // exibe o help
            break;
        case GLUT_KEY_F2:
            cam.type = TOPDOWN_CAM;
            break;
        case GLUT_KEY_F3:
            cam.type = FOCUSED_CAM;
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
        glutInitWindowSize(WIDTH, HEIGHT);
        glutInitWindowPosition(20, 20);
        glutCreateWindow("Maze");
        glutDisplayFunc(onDisplay);
        glutReshapeFunc(onResize);
        glutKeyboardFunc(onPressKey);
        glutSpecialFunc(onPressKeySp);
        Init();
    glutMainLoop();
}
