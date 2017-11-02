/*
*   Universidade Federal da Fronteira Sul
*   Ciência da Computação 7ª Fase - Computação Gráfica 2017.II
*   Trabalho 1
*   Acadêmico: Nicholas Sangoi Brutti (1421101033)
*/

#include <GL/freeglut.h>
#include <cstdio>
#include <math.h>
#include "robot.h"
#include "objects.h"

void Robot::Draw() {
    GLUquadricObj *sphere = gluNewQuadric();
    GLUquadricObj *cylinder = gluNewQuadric();

    if(!isWalking)
        rotx = .0;

    // Cabeça
    glPushMatrix();
        glRotatef(rotx, 0.0f, 1.0f, 0.05f);
        // Boca
        /*glPushMatrix();
            glColor3f(1.0f, 0.0f, 0.0f);
            glRotatef(-180, 1.0f, 0.0f, 0.0f);
            glTranslatef(0.0f, -10.0f, 1.5f);
            glScalef(1.5f, 0.5f, 0.0f);
            gluCylinder(cylinder, 1.3f, 1.1f, 0.0f, 100, 100);
        glPopMatrix();*/

        // Olhos
        glPushMatrix();
            // Cilindro que fica envolta dos olhos
            glPushMatrix();
                glColor3fv(members_color);
                glTranslatef(0.0f, 12.2f, -2.0f);
                glScalef(1.3, 0.75, 1);
                gluCylinder(cylinder, 1.2f, 1.1f, 2.0f, 100, 100);
            glPopMatrix();

            glColor3f(1.0f, 1.0f, 0.6f);
            glRotatef(180, 0.0f, 1.0f, 0.0f);
            // Olho esquerdo
            glTranslatef(-0.5f, 12.0f, 1.2f);
            glutSolidSphere(0.6, 100, 100);
            glColor3f(0.0f, 0.0f, 0.0f);
            glTranslatef(0.0f, 0.1f, 0.5f);
            glutSolidSphere(0.2, 100, 100);
            // Olho direito
            glColor3f(1.0f, 1.0f, 0.6f);
            glTranslatef(1.0f, 0.0f, -0.5f);
            glutSolidSphere(0.6, 100, 100);
            glColor3f(0.0f, 0.0f, 0.0f);
            glTranslatef(0.0f, 0.0f, 0.5f);
            glutSolidSphere(0.2, 100, 100);
        glPopMatrix();

        glColor3fv(body_color);
        glTranslatef(0.0, 7.0f, 0.0f);
        glRotatef(-90, 1.0f, 0.0f, 0.0f);
        gluCylinder(cylinder, 1.5f, 1.5f, 6.0f, 100, 100);

        // Efeito rounded
        glRotatef(90, 1.0f, 0.0f, 0.0f);
        glTranslatef(0.0f, 6.0f, 0.0f);
        glutSolidSphere(1.5f, 100, 100);
    glPopMatrix();

    // Antena
    glPushMatrix();
        glColor3fv(body_color);
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
        if(isWalking) glRotatef(-rotx - 5, 1.0f, 0.0f, 0.0f);
        // Braço esquerdo
        glPushMatrix();
            glColor3fv(members_color);
            glTranslatef(3.5f, 4.5f, 0.0f);
            glRotatef(90, 1.0f, 0.0f, 0.0f);
            //glRotatef(15, 1.0f, 1.0f, 0.0f);
            gluCylinder(cylinder, 0.5f, 0.5f, 10.0f, 100, 100);
        glPopMatrix();

        // Mão esquerda
        glPushMatrix();
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        if(isWalking) glRotatef(rotx + 5, 1.0f, 0.0f, 0.0f);
        // Braço direito
        glColor3fv(members_color);
        glPushMatrix();
            glTranslatef(-3.5f, 4.5f, 0.0f);
            glRotatef(90, 1.0f, 0.0f, 0.0f);
            gluCylinder(cylinder, 0.5f, 0.5f, 10.0f, 100, 100);
        glPopMatrix();

        // Mão direita
        glPushMatrix();
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        if(isWalking) glRotatef(-rotx, 1.0f, 0.0f, 0.0f);
        glTranslatef(0, 0, 0);
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
        if(isWalking) glRotatef(rotx, 1.0f, 0.0f, 0.0f);
        glTranslatef(0, 0, 0);
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
    if(rotx < 15 && !flag) rotx += 1.5;
    else if (rotx > 0) flag = true;
    if(flag) {
        rotx -= 1.5;
        if(rotx == -15) flag = false;
    }
}
