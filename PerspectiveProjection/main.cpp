#include<windows.h>
#include<gl/glut.h>

void init() {
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(60, 1, 0.01, 100);
	//gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
	gluLookAt(1, 2, 5, 0, 0, 0, 0, 1, 0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	//glRotatef(45,0,1,0);
	glutSolidCube(1);
	glFlush();

}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(600, 600);
	glutCreateWindow("simple cube");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
