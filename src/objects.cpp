/*
*   Universidade Federal da Fronteira Sul
*   Ciência da Computação 7ª Fase - Computação Gráfica 2017.II
*   Trabalho 1
*   Acadêmico: Nicholas Sangoi Brutti (1421101033)
*/

#include <GL/freeglut.h>
#include "objects.h"

#define MESA_X 200
#define MESA_Z 420

// Desenha uma mesa e uma chaleira
void drawObj1() {
    glPushMatrix();
        glTranslatef(-180, 0, 0);
        glColor3f(0.6f, 0.3f, 0.0f);

        glPushMatrix();
            glTranslatef(MESA_X, 10, MESA_Z);
            glScalef(1, 5, 1);
            glutSolidCube(3);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(MESA_X + 20, 10, MESA_Z);
            glScalef(1, 5, 1);
            glutSolidCube(3);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(MESA_X + 20, 10, MESA_Z - 10);
            glScalef(1, 5, 1);
            glutSolidCube(3);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(MESA_X, 10, MESA_Z - 10);
            glScalef(1, 5, 1);
            glutSolidCube(3);
        glPopMatrix();

        glPushMatrix();
            glBegin(GL_QUADS);
                glVertex3f(MESA_X - 5, 17.5, MESA_Z + 2);
                glVertex3f(MESA_X + 25, 17.5, MESA_Z + 2);
                glVertex3f(MESA_X + 25, 17.5, MESA_Z - 12);
                glVertex3f(MESA_X - 5, 17.5, MESA_Z - 12);
            glEnd();
            glFlush();
            glColor3f(1.0f, 0.8f, 0);
            glTranslatef(MESA_X + 10, 21.0, MESA_Z - 5);
            glutSolidTeapot(3.0);
        glPopMatrix();

    glPopMatrix();
}

// Desenha uma mesa de Ping-Pong
void drawObj2() {
    glPushMatrix();
        glTranslatef(-180, 0, 0);
        glColor3f(0.6f, 0.3f, 0.0f);

        glTranslatef(160, 0, 0);

        glPushMatrix();
            glTranslatef(MESA_X, 10, MESA_Z);
            glScalef(1, 5, 1);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(MESA_X + 7, 10, MESA_Z);
            glScalef(1, 5, 1);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(MESA_X + 7, 10, MESA_Z - 7);
            glScalef(1, 5, 1);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(MESA_X, 10, MESA_Z - 7);
            glScalef(1, 5, 1);
            glutSolidCube(1);
        glPopMatrix();

        glColor3f(0.0f, 0.4f, 0.0f);

        glPushMatrix();
            glBegin(GL_QUADS);
                glVertex3f(MESA_X - 0.5, 12.6, MESA_Z + 0.5);
                glVertex3f(MESA_X + 7.5, 12.6, MESA_Z + 0.5);
                glVertex3f(MESA_X + 7.5, 12.6, MESA_Z - 7.5);
                glVertex3f(MESA_X - 0.5, 12.6, MESA_Z - 7.5);
            glEnd();
            glFlush();
        glPopMatrix();

        glPushMatrix();
            glBegin(GL_QUADS);
                glVertex3f(MESA_X - 0.5, 12.5, MESA_Z - 7.5);
                glVertex3f(MESA_X + 7.5, 12.5, MESA_Z - 7.5);
                glVertex3f(MESA_X + 7.5, 18.5, MESA_Z - 7.5);
                glVertex3f(MESA_X - 0.5, 18.5, MESA_Z - 7.5);
            glEnd();
            glFlush();
        glPopMatrix();

    glPopMatrix();
}

void Objects::Draw() {
    glPushMatrix();
        glTranslatef(5, -25, -398);
        drawObj1();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(35, -30, -398);
        glScalef(1, 2, 1);
        drawObj2();
    glPopMatrix();
}
