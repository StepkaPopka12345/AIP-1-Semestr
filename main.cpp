#include "GL/freeglut.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "Lib(pict).h" 
float pos_x = -5, pos_y = 5.2;

void renderScene(void);
bool isVictory = false;
bool isDeaf = false;
bool isGetApple[3] = { false,false,false};
bool isOpenDoor[3] = { false, false, false };
bool isVictory1 = false;
// блок реализации функций

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("OpenGL Start Application");
    glutDisplayFunc(renderScene);
	glutKeyboardFunc(processKeys);
    glutMainLoop();
    return 0;
}

void renderScene(void) {
   
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // эта функция должна быть первой в renderScene
       glPushMatrix();
    drawCSENA();
    drawWalls();
    if (isVictory1)
    drawViktory();

    drawExcit(0.3,-0.5);
    if (!isVictory1)
    drawCat(pos_x, pos_y ,0);
   
    
    
    glutSwapBuffers(); // эта функция должна быть последний в renderScene
}

void processKeys(unsigned char key, int x, int y) {

    if (key == 113)
        exit(0); // close app закрывается на Q
    if (key == 100) {
        pos_x = pos_x + 0.1;//вправо на D

    }
    if (key == 97) {
        pos_x = pos_x - 0.1;//влево на A

    }

    if (key == 119) {
        pos_y = pos_y + 0.1;//вверх на W

    }
    if (key == 115) {
        pos_y = pos_y - 0.1;//вниз на S

    }
   if (((pos_x>=-5.7) && (pos_x<=4.3) &&(pos_y>=2.4)&&(pos_y<=4.3))
       || ((pos_x >= 0) && (pos_x <= 0) && (pos_y >= 0) && (pos_y <= 0))
       || ((pos_x >= -9) && (pos_x <= 9) && (pos_y >=5.8)&&(pos_y <= 9))
       || ((pos_x >= 5.9) && (pos_x <= 9) && (pos_y >= -10) && (pos_y <= 5.6))
       || ((pos_x >= -9) && (pos_x <= 9) && (pos_y >= -10) && (pos_y <= -5.9))
       || ((pos_x >= -10) && (pos_x <= -5.6) && (pos_y >= -10) && (pos_y <= 5.7))
       || ((pos_x >= -9) && (pos_x <= -.8) && (pos_y >= -0.1) && (pos_y <= 1.6))
       || ((pos_x >= 1.5) && (pos_x <= 9) && (pos_y >= 0) && (pos_y <= 1))
       )
       pos_x = -5, pos_y = 5.2;
   if ((pos_x >= 4.7) && (pos_x <= 9) && (pos_y >= -.7) && (pos_y <= 0))
       isVictory1 = true;
   
    glutPostRedisplay(); // отрисовка
}
