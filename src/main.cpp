/*
*   Universidade Federal da Fronteira Sul
*   Ciência da Computação 7ª Fase - Computação Gráfica 2017.II
*   Trabalho 1
*   Acadêmico: Nicholas Sangoi Brutti (1421101033)
*/

#include <GL/freeglut.h>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include "robot.h"
#include "maze.h"
#include "camera.h"
#include "objects.h"

#define WIDTH 800
#define HEIGHT 600
#define FPS 100

Objects ob;
Camera cam;
Maze m;
Robot r;

int pos = 0;
// angle of rotation for the camera direction
float angle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f;
float fraction = 1.0f;
float rot = .0;
bool flag = true;

void Init() {
    // Texturas
    char *filenameArray[2] = {
        (char *) WALL_TEXTURE_SRC,
        (char *) FLOOR_TEXTURE_SRC
    };
    
    // Posição incial do robo
    r.x = 480;
    r.y = 4.0f;
    r.z = 480;

    // Inicialização da camera
    cam.z = 700.0f;
    cam.type = TOPDOWN_CAM;

    // Carrega as texturas
    m.initTextures(filenameArray);
    

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    // Habilita o z-buffer
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_MULTISAMPLE);
    glDepthFunc(GL_LESS);
}

void onDisplay() {
    // Seleciona a matriz de MODELVIEW
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(cam.type == TOPDOWN_CAM)
        gluLookAt(VIEW_SIZE/2, cam.z, 300.0 , VIEW_SIZE/2, 10.0, VIEW_SIZE/2, 0.0, 1.0, 0.0);
    else if(cam.type == FOCUSED_CAM)
        gluLookAt(r.x - (WALL_SIZE*3) * sin(angle), 60.0f, r.z + (WALL_SIZE*3) * cos(angle), r.x + lx, 20.0, r.z + lz, 0.0, 1.0, 0.0);

    // Desenha o chão
    m.renderScene();

    glPushMatrix();
        m.renderMaze();
        ob.Draw();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(r.x, r.y, r.z);
        glRotatef(-rot, 0.0f, 1.0f, 0.0f);
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
    switch (tolower(key)) {
        case 'w':
            r.isWalking = true;
            r.x += lx * fraction;
            r.z += lz * fraction;
            break;
        case 'a':
            r.isWalking = false;
            angle -= 1.5554f;
            lx = sin(angle);
            lz = -cos(angle);
            rot -= 90.0f;
            if(rot == 0 || abs(rot) == 180) lx = 0.0f;
            pos--;
            break;
        case 's':
            r.isWalking = true;
            r.x -= lx * fraction;
            r.z -= lz * fraction;
            break;
        case 'd':
            r.isWalking = false;
            angle += 1.5554f;
            lx = sin(angle);
            lz = -cos(angle);
            rot += 90.0f;
            if(rot == 0 || abs(rot) == 180) lx = 0.0f;
            pos++;
            break;
        case '-':
            cam.z -= 10;
            break;
        case '+':
            cam.z += 10;
            break;
        case 'e':
          lx = 0.0f;
          break;
    }
    if(abs(pos) == 4) {
        pos = lx = rot = angle = .0;
        lz = -1;
    }
    glutPostRedisplay();
}

void onPressKeySp(int key, int x, int y) {
    switch (key) {
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

void Timer(int a) {
    if(r.isWalking == true) {
        r.Walk();
    }
    glutPostRedisplay();
    glutTimerFunc(1000.0/FPS, Timer, 1);
}

void onKeyUp(unsigned char key, int x, int y) {
    if(tolower(key) == 'w' || tolower(key)  == 's') r.isWalking = false;
}

void InitLight( ){
    GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};	   // "cor"
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho"
	GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
	GLint especMaterial = 60;

 	// Especifica que a cor de fundo da janela será preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
        glutInitWindowSize(WIDTH, HEIGHT);
        glutInitWindowPosition(20, 20);
        glutCreateWindow("Maze");
        glutDisplayFunc(onDisplay);
        glutReshapeFunc(onResize);
        glutKeyboardFunc(onPressKey);
        glutSpecialFunc(onPressKeySp);
        glutKeyboardUpFunc(onKeyUp);
        glutTimerFunc(1000.0/FPS, Timer, 1);
        InitLight();
        Init();
    glutMainLoop();
}
