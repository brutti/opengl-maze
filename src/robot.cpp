#include <GL/freeglut.h>
#include <cstdio>
#include "robot.h"

void Robot::Draw() {
    GLUquadricObj *cylinder = gluNewQuadric();
    GLfloat v_body[8][3] = {
        {-2.0, -3.0, -2.0},
        {-2.0, 3.0, -2.0},
        {2.0, 3.0, -2.0},
        {2.0, -3.0, -2.0},
        {-2.0, -3.0, 2.0},
        {-2.0, 3.0, 2.0},
        {2.0, 3.0, 2.0},
        {2.0, -3.0, 2.0}
    };

    // Cabeça
    glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f);
        glTranslatef(0.0f, 5.0f, 0.0f);
        glutSolidCube(3);
    glPopMatrix();

    // Pescoço
    glPushMatrix();
        glTranslatef(0.0f, 3.5f, 0.0f);
        glRotatef(90, 1.0f, 0.0f, 0.0f);
        gluCylinder(cylinder, 0.4f, 0.4f, 1.0f, 50, 50);
    glPopMatrix();

    // Tronco
    glPushMatrix();
        glTranslatef(0.0f, -0.5f, 0.0f);
        glBegin(GL_QUADS);
            // Frente
            glVertex3fv(v_body[0]);
            glVertex3fv(v_body[1]);
            glVertex3fv(v_body[2]);
            glVertex3fv(v_body[3]);
            
            // Fundo
            glVertex3fv(v_body[4]);
            glVertex3fv(v_body[5]);
            glVertex3fv(v_body[6]);
            glVertex3fv(v_body[7]);

            // Esquerda
            glVertex3fv(v_body[3]);
            glVertex3fv(v_body[7]);
            glVertex3fv(v_body[6]);
            glVertex3fv(v_body[2]);

            // Direita
            glVertex3fv(v_body[0]);
            glVertex3fv(v_body[4]);
            glVertex3fv(v_body[5]);
            glVertex3fv(v_body[1]);

            // Cima
            glVertex3fv(v_body[1]);
            glVertex3fv(v_body[5]);
            glVertex3fv(v_body[6]);
            glVertex3fv(v_body[2]);
            
            // Baixo
            glVertex3fv(v_body[0]);
            glVertex3fv(v_body[4]);
            glVertex3fv(v_body[7]);
            glVertex3fv(v_body[3]);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.3f, -5.0f, 0.0f);
        glRotatef(90, 1.0f, 0.0f, 0.0f);
        glutSolidTorus(0.3f, 0.6f, 100, 100);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-1.3f, -5.0f, 0.0f);
        glRotatef(90, 1.0f, 0.0f, 0.0f);
        glutSolidTorus(0.3f, 0.6f, 100, 100);
    glPopMatrix();

    // Perna Esq e Dir.
    for (double count = -5.5; count >= -7; count -= 0.5) {
        glPushMatrix();
            glTranslatef(1.3f, count, 0.0f);
            glRotatef(90, 1.0f, 0.0f, 0.0f);
            glutSolidTorus(0.2f, 0.4f, 100, 100);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-1.3f, count, 0.0f);
            glRotatef(90, 1.0f, 0.0f, 0.0f);
            glutSolidTorus(0.2f, 0.4f, 100, 100);
        glPopMatrix();
    }
}

void Robot::Walk() {

}