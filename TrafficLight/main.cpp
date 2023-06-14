#include <GL/glut.h>
#include<math.h>

int currentColor = 0;
int redTime = 5; // Time in seconds
int yellowTime = 2; // Time in seconds
int greenTime = 5; // Time in seconds
int timer = 0;

void drawCircle(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i < 360; i++) {
       glVertex2f(x + radius * cos(i * 3.14159 / 180.0), y + radius * sin(i * 3.14159 / 180.0));
   }
    glEnd();
}

void drawTrafficLight() {
    // Draw the traffic light box
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex2f(-0.1, -0.6);
    glVertex2f(-0.1, 0.6);
    glVertex2f(0.1, 0.6);
    glVertex2f(0.1, -0.6);
    glEnd();

    // Draw the red light
    if (currentColor == 0) {
        glColor3f(1.0, 0.0, 0.0);
    }
    else {
        glColor3f(0.3, 0.0, 0.0);
    }
    drawCircle(0, 0.4, 0.15);

    // Draw the yellow light
    if (currentColor == 1) {
        glColor3f(1.0, 1.0, 0.0);
    }
    else {
        glColor3f(0.3, 0.3, 0.0);
    }
    drawCircle(0, 0, 0.15);

    // Draw the green light
    if (currentColor == 2) {
        glColor3f(0.0, 1.0, 0.0);
    }
    else {
        glColor3f(0.0, 0.3, 0.0);
    }
    drawCircle(0, -0.4, 0.15);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawTrafficLight();
    glutSwapBuffers();
}

void timerFunction(int value) {
    timer++;
    if (timer >= redTime + yellowTime + greenTime) {
        timer = 0;
    }
    if (timer < redTime) {
        currentColor = 0; // Red
    }
    else if (timer < redTime + yellowTime) {
        currentColor = 1;// Yellow
    }
    else {
        currentColor = 2; // Green
    }
    glutPostRedisplay();
    glutTimerFunc(1000, timerFunction, 0); // 1000 milliseconds = 1 second
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 600);
    glutCreateWindow("Traffic Light");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.5, 1.5);
    glutDisplayFunc(display);
    glutTimerFunc(1000, timerFunction, 0);
    glutMainLoop();
    return 0;
}
