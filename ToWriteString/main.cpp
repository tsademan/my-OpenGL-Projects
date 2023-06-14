#include<windows.h>
#include<gl/glut.h>

void init()
{
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-20,20,-20,20,-20,20);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    glRasterPos2i(2,4);
    const char*mystring ="Hello,World";
    for(int i=0;i<strlen(mystring);++i)
    {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,mystring[i]);
    }
 glFlush();
}

int main(int arg,char** argv)
{
    glutInit(&arg,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowPosition(700,600);
    glutInitWindowSize(500,400);
    glutCreateWindow("my string");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;

}
