
#include<gl/glut.h>
bool light1Enabled = false;

void init()
{
   // gluPerspective(-20, 20, 0.1, 100.0);
   //  glMatrixMode(GL_MODELVIEW);
   glMatrixMode(GL_PROJECTION);
   glOrtho(-20,20,-20,20,-20,20);
    GLfloat mat_ambient[]={1.0,0.3,0.5,1.0};
    GLfloat mat_diffuse[]={0.0,0.6,0.0,1.0};
    GLfloat mat_specular[]={1.0,1.0,1.0,0.0};
    GLfloat mat_shininess[]={20.0};

    GLfloat light1_position[]={1.0,1.0,1.0,1.0};

      glClearColor(0.0, 0.0, 0.0, 0.0);
      glShadeModel(GL_SMOOTH);

        glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);



    glDisable(GL_LIGHT1);
    glEnable(GL_DEPTH_TEST);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glutSolidCube(4);
    glFlush();
}
void keyboard(unsigned char key, int x, int y)
{
    if (key == '1')
    {
        light1Enabled = !light1Enabled;

        if (light1Enabled)
            glEnable(GL_LIGHT1);
        else
            glDisable(GL_LIGHT1);

        glutPostRedisplay(); // Mark the window for redisplay
    }
}
int main(int arg , char** argv)
{
    glutInit(&arg,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,400);
    glutCreateWindow("lighting");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
