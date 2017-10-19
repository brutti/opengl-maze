#include <GL/freeglut.h>
#include <cstdio>
#include "robot.h"

void Robot::Draw() {
    GLUquadricObj *sphere = gluNewQuadric();
    GLUquadricObj *cylinder = gluNewQuadric();

    // Cabeça
    glPushMatrix();
        glColor3fv(body_color);
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
        glColor3fv(members_color);
        glTranslatef(-3.5f, 4.0f, 0.0f);
        glRotatef(90, 0.0f, 1.0f, 0.0f);
        glutSolidTorus(0.35f, 0.75f, 100, 100);
    glPopMatrix();

    glPushMatrix();
        glColor3fv(members_color);
        glTranslatef(3.5f, 4.0f, 0.0f);
        glRotatef(90, 0.0f, 1.0f, 0.0f);
        glutSolidTorus(0.35f, 0.75f, 100, 100);
    glPopMatrix();

    glPushMatrix();
        // Braço esquerdo
        glPushMatrix();
            glColor3fv(members_color);
            glTranslatef(3.5f, 4.5f, 0.0f);
            glRotatef(90, 1.0f, 0.0f, 0.0f);
            glRotatef(15, 1.0f, 1.0f, 0.0f);
            gluCylinder(cylinder, 0.5f, 0.5f, 10.0f, 100, 100);
        glPopMatrix();

        // Mão esquerda
        glPushMatrix();
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        // Braço direito
        glColor3fv(members_color);
        glPushMatrix();
            glTranslatef(-3.5f, 4.5f, 0.0f);
            glRotatef(90, 1.0f, 0.0f, 0.0f);
            glRotatef(-15, 1.0f, 1.0f, 0.0f);
            gluCylinder(cylinder, 0.5f, 0.5f, 10.0f, 100, 100);
        glPopMatrix();

        // Mão direita
        glPushMatrix();
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0, 0, 2);
        // Perna direita
        glPushMatrix();
            glColor3fv(members_color);
            glTranslatef(-1.6f, -5.0f, 0.0f);
            glRotatef(90, 1.0f, 0.0f, 0.0f);
            gluCylinder(cylinder, 0.5f, 0.5f, 10.0f, 100, 100);
        glPopMatrix();

        // Pé direito
        glPushMatrix();
            glColor3fv(body_color);
            glTranslatef(-1.6f, -16.0f, 0.0f);
            glRotatef(-90, 1.0f, 0.0f, 0.0f);
            SOLID_CLOSED_CYLINDER(cylinder, 1.5f, 1.0f, 1.0f, 100, 100);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0, 0, 2);
        // Perna esquerda
        glPushMatrix();
            glColor3fv(members_color);
            glTranslatef(1.6f, -5.0f, 0.0f);
            glRotatef(90, 1.0f, 0.0f, 0.0f);
            gluCylinder(cylinder, 0.5f, 0.5f, 10.0f, 100, 100);
        glPopMatrix();

        // Pé esquerdo
        glPushMatrix();
            glColor3fv(body_color);
            glTranslatef(1.6f, -16.0f, 0.0f);
            glRotatef(-90, 1.0f, 0.0f, 0.0f);
            SOLID_CLOSED_CYLINDER(cylinder, 1.5f, 1.0f, 1.0f, 100, 100);
        glPopMatrix();
    glPopMatrix();
}

void Robot::Walk() {

}
