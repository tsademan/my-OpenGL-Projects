#include<windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

float angle = 90, ty = 0;

void initGL() {
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-30, 30, -30, 30, -30, 30);
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 0);

    glPushMatrix();
    glColor3f(0, 0, 0);
    glRotated(angle, 0, 0, 1);
    glutSolidCube(4);
    glPopMatrix();
    glFlush();
}
void move(){
    angle +=0.01;
glutPostRedisplay();

}

void handleKeypress(unsigned char key, int x, int y) {
  switch (key) {
    case 'w':
     angle += 10;
      break;
    case 's':
     angle -= 10;
      break;
    default:
      break;
  }
  glutPostRedisplay();
}
void mouseHandling(int button,int state,int x,int y)
{
   switch(button)
    {
    case GLUT_LEFT_BUTTON:
        angle -= 10;
        break;
    case GLUT_RIGHT_BUTTON:
        angle += 10;
        break;
    default:
        break;
    }
}
int main(int a, char** b) {

    glutInit(&a, b);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("cube");
    initGL();
    glutDisplayFunc(display);
    glutIdleFunc(move);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(mouseHandling);
    glutMainLoop();
    return 0;
}
