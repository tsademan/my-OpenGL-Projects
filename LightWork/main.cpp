#include <Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

double tx = 0;

void init() {
    glClearColor(1, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-20, 20, -20, 20, -20, 20);

    // Enable lighting and set lighting model
    glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH);

    // Define position and properties of light source
    GLfloat light_position[] = { 0.0, 0.0, 1.0, 0.0 };
    GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
    glEnable(GL_LIGHT0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set material properties of cube
    GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
    GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 100.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    // Draw cube with normal vectors

    glBegin(GL_QUADS);
       glColor3f(0,0,0);
        glNormal3f(0.0, 0.0, 1.0);
        glVertex3f(-2.5, -2.5, 2.5);
        glVertex3f(2.5, -2.5, 2.5);
        glVertex3f(2.5,2.5, 2.5);
        glVertex3f(-2.5, 2.5, 2.5);
    glEnd();

    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN) {
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
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(600, 700);
    glutCreateWindow("sample");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    init();
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
