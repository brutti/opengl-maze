/*
*   Universidade Federal da Fronteira Sul
*   Ciência da Computação 7ª Fase - Computação Gráfica 2017.II
*   Trabalho 1
*   Acadêmico: Nicholas Sangoi Brutti (1421101033)
*/

#include <GL/freeglut.h>
#include "RgbImage.h"
#include "maze.h"

void Maze::initTextures(char* filenames[]) {
	glGenTextures(2, textures);	// Load four texture names into array
	for (int i = 0; i < 2; i++) {
		glBindTexture(GL_TEXTURE_2D, textures[i]);	// Texture #i is active now
		loadTextureFromFile(filenames[i]);			// Load texture #i
	}
}

void Maze::loadTextureFromFile(char *filename) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap( filename );

	// Set the interpolation settings to best quality.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB,
					 theTexMap.GetNumCols(), theTexMap.GetNumRows(),
					 GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData() );    
}

void Maze::drawFloor(int size) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[1]);

    glBegin(GL_QUADS);
    
        glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, size);
        glTexCoord2f(0.0, 1.0); glVertex3f(size, 0.0, size);
        glTexCoord2f(1.0, 1.0); glVertex3f(size, 0.0, 0.0);
        glTexCoord2f(1.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
   
   glEnd();

   glFlush();
   glDisable(GL_TEXTURE_2D);
}

void Maze::drawWall() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[0]);

    glBegin(GL_QUADS);
        // Front Face
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
        // Back Face
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
        // Top Face
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
        // Bottom Face
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        // Right face
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
        // Left Face
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
    glEnd();

    glFlush();
    glDisable(GL_TEXTURE_2D);
}

void Maze::renderScene() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
        glTranslatef(0.0f, -20.0f, 0.0f);
        for(int j = 0; j < 11; j++) {
            for(int i = 0; i < 11; i++) {
                drawFloor(50);
                glTranslatef(50.0f, 0.0f, 0.0f);
            }
            glTranslatef(-VIEW_SIZE, 0.0f, 50.f);
        }
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
                    glScalef(8, 30, 8);
                    drawWall();
                glPopMatrix();
            }
        }
    }
}
