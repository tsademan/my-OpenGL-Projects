#include<Windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

double tx = 0;
void init() {
	glClearColor(1,0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-20, 20, -20, 20, -20, 20);
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	  glPushMatrix();
	    glColor3f(0, 0, 0);
	    glTranslated(0,0,tx);
	    glutSolidCube(5);
      glPopMatrix();
	glFlush();
}

void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		tx -= 0.1;
		break;
	case GLUT_RIGHT_BUTTON:
		tx += 0.1;
		break;

	default:
		break;

	}
}

int main(int arge, char** argv) {
	glutInit(&arge, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(600, 700);
	glutCreateWindow("sample");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	init();
	glutMainLoop();
	return 0;
}
