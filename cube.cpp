

/**
#include<GL/glut.h>
#include<GL/gl.h>
#include<iostream>
#include<cmath>
GLint x,y;
using namespace std;


void init()
{
glClearColor(0,0,1,0);
glColor3f(0,1,0);
glPointSize(3.0);
gluOrtho2D(0,700,0,700);	
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	
	glVertex2i(x,y);
	glVertex2i(x+100,y-50);
	glVertex2i(x+200,y);
	glVertex2i(x+100,y+50);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(x,y);
	glVertex2i(x,y-150);
	glVertex2i(x+100,y-200);
	glVertex2i(x+200,y-150);
	glVertex2i(x+200,y);
	glVertex2i(x+100,y-50);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(x+100,y-50);
	glVertex2i(x+100,y-200);
	glEnd();
	glFlush();
	
	
}

int main(int argc,char** argv)
{
	cout<<"Enter x and y:";
	cin>>x>>y;
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,100);
	glutCreateWindow("2D Cube");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

/**/
