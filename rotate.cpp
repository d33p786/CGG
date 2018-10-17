#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
float x1,x2,y11,y2;
float nx1,ny1,nx2,ny2,nx3,ny3,nx4,ny4,t,r;
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0,0.0,0.0);
	  	glVertex2f(x1,y11);
	  	glVertex2f(x2,y11);
	  	glVertex2f(x2,y2);
	  	glVertex2f(x1,y2);
	glEnd();
	

	 t=3.14*r/180;
    nx1=(x1*cos(t)-y11*sin(t));
    ny1=(x1*sin(t)+y11*cos(t));
    nx2=(x2*cos(t)-y2*sin(t));
    ny2=(x2*sin(t)+y2*cos(t));
    nx3=(x2*cos(t)-y11*sin(t));
    ny3=(x2*sin(t)+y11*cos(t));
	nx4=(x1*cos(t)-y2*sin(t));
    ny4=(x1*sin(t)+y2*cos(t));
    
    
    
	glBegin(GL_LINE_LOOP);
	
	glColor3f(0.0,1.0,1.0);
	
	glVertex2f(nx1,ny1);
	glVertex2f(nx3,ny3);
	glVertex2f(nx2,ny2);
glVertex2f(nx4,ny4);

	glEnd();
		
	glFlush();
}

void init()
{
    glClearColor(0.0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300,300,-300,300);
}

int main(int argc, char** argv)
{
	printf("Values for the Original Square: \n\n");
	printf("\nEnter the value of x1 - ");
	scanf("%f",&x1);
	printf("Enter the value of y1 - ");
	scanf("%f",&y11);
	printf("Enter the value of x2 - ");
	scanf("%f",&x2);
	printf("Enter the value of y2 - ");
	scanf("%f",&y2);
	 printf("\n Enter the angle of rotation");
    scanf("%f",&r);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
          glutInitWindowPosition(0,0);
	glutCreateWindow("rotation");
	glutDisplayFunc(display);
	init();
	glutMainLoop(); 
	
	return 0;
}

