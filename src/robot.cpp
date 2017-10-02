#include <GL/freeglut.h>
#include <cstdio>
#include "robot.h"

void Robot::Draw() {
    GLUquadricObj *sphere = gluNewQuadric();
    GLUquadricObj *cylinder = gluNewQuadric();

    // Cabeça
    glPushMatrix();
        glColor3f(0.55f, 0.65f, 0.73f);
        glTranslatef(0.0, 7.0f, 0.0f);
        glRotatef(-90, 1.0f, 0.0f, 0.0f);
        gluCylinder(cylinder, 1.5f, 1.5f, 6.0f, 100, 100);

        // Efeito rounded
        glRotatef(90, 1.0f, 0.0f, 0.0f);
        glTranslatef(0.0f, 6.0f, 0.0f);
        glutSolidCone(1.5f, 0.0f, 100, 100);
    glPopMatrix();

    // Antena
    glPushMatrix();
        glTranslatef(0.0f, 16.5f, 0.0f);
        glRotatef(90, 1.0f, 0.0f, 0.0f);
        gluCylinder(cylinder, 0.05f, 0.25f, 2.0f, 100, 100);
        gluSphere(sphere, 0.25f, 100, 100);
    glPopMatrix();

    // Tronco
    glPushMatrix();
        glTranslatef(0.0f, 7.0f, 0.0f);
        glRotatef(90, 1.0f, 0.0f, 0.0f);
        gluCylinder(cylinder, 1.5f, 3.5f, 2.0f, 100, 100);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0f, -5.0f, 0.0f);
        glRotatef(-90, 1.0f, 0.0f, 0.0f);
        gluCylinder(cylinder, 2.5f, 3.5f, 10.0f, 100, 100);
    glPopMatrix();

    // Ombros
    glPushMatrix();
        glColor3f(0.35f, 0.45f, 0.53f);
        glTranslatef(-3.5f, 4.0f, 0.0f);
        glRotatef(90, 0.0f, 1.0f, 0.0f);
        glutSolidTorus(0.35f, 0.75f, 100, 100);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.35f, 0.45f, 0.53f);
        glTranslatef(3.5f, 4.0f, 0.0f);
        glRotatef(90, 0.0f, 1.0f, 0.0f);
        glutSolidTorus(0.35f, 0.75f, 100, 100);
    glPopMatrix();

    // Braço esquerdo
    glPushMatrix();
        glTranslatef(3.5f, 4.5f, 0.0f);
        glRotatef(90, 1.0f, 0.0f, 0.0f);
        glRotatef(15, 1.0f, 1.0f, 0.0f);
        gluCylinder(cylinder, 0.5f, 0.5f, 10.0f, 100, 100);
    glPopMatrix();

    // Braço direito
    glPushMatrix();
        glTranslatef(-3.5f, 4.5f, 0.0f);
        glRotatef(90, 1.0f, 0.0f, 0.0f);
        glRotatef(-15, 1.0f, 1.0f, 0.0f);
        gluCylinder(cylinder, 0.5f, 0.5f, 10.0f, 100, 100);
    glPopMatrix();

    // Perna direita
    glPushMatrix();
        glTranslatef(-1.6f, -5.0f, 0.0f);
        glRotatef(90, 1.0f, 0.0f, 0.0f);
        gluCylinder(cylinder, 0.5f, 0.5f, 12.0f, 100, 100);
    glPopMatrix();

    // Perna esquerda
    glPushMatrix();
        glTranslatef(1.6f, -5.0f, 0.0f);
        glRotatef(90, 1.0f, 0.0f, 0.0f);
        gluCylinder(cylinder, 0.5f, 0.5f, 12.0f, 100, 100);
    glPopMatrix();
}

void Robot::Walk() {

}