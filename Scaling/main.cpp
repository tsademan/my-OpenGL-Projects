#include<windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

//float angle = 90, ty = 0;

void initGL() {
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-30, 30, -30, 30, -30, 30);
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    glPushMatrix();
    glScaled(2.0, 2.0, 2.0); // Scale the object by a factor of 2 along all axes
    glutSolidCube(4);
    glPopMatrix();
    glFlush();
}
void handleKeypress(unsigned char key, int x, int y) {
  switch (key) {
    case 'w':
     glScaled(1.1, 1.1, 1.1); // Increase the scaling factor by 10%
      break;
    case 's':
     glScaled(0.9, 0.9, 0.9); // Decrease the scaling factor by 10%
      break;
    default:
      break;
  }
  glutPostRedisplay();
}

int main(int a, char** b) {

    glutInit(&a, b);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("cube");
    initGL();
    glutDisplayFunc(display);
    //glutIdleFunc(move);
    glutKeyboardFunc(handleKeypress);
    //glutMouseFunc(mouseHandling);
    glutMainLoop();
    return 0;
}
