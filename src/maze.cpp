/*
*   Universidade Federal da Fronteira Sul
*   Ciência da Computação 7ª Fase - Computação Gráfica 2017.II
*   Trabalho 1
*   Acadêmico: Nicholas Sangoi Brutti (1421101033)
*/

#include <GL/freeglut.h>
#include "maze.h"

void Maze::renderScene() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
        glTranslatef(0.0f, -20.0f, 0.0f);
        glBegin(GL_QUADS);
            glColor3f(0.3f, 0.3f, 0.3f);
    		glVertex3f(0, 0, VIEW_SIZE);
    		glVertex3f(VIEW_SIZE, 0, VIEW_SIZE);
    		glVertex3f(VIEW_SIZE, 0, 0);
    		glVertex3f(0, 0, 0);
        glEnd();
    glPopMatrix();
}

void Maze::renderMaze() {
    int xpos = 0, zpos = 0;

    glTranslatef(35.0f, 0.0f, 40.0f);
    glColor3f(1.0f, 1.0f, 1.0f);

    for(int i = 0; i < MAZE_SIZE; i++) {
        for(int j = 0; j < MAZE_SIZE; j++) {
            if(M[j][i]) {
                xpos = WALL_SIZE * i;
                zpos = WALL_SIZE * j;
                glPushMatrix();
                    glTranslatef(xpos, 10.0f, zpos);
                    glScalef(1, 3.5, 1);
                    glutSolidCube(WALL_SIZE);
                glPopMatrix();
            }
        }
    }
}
