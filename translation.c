#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
float x1,x2,y11,y2,t1,t2;

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
	
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,1.0,1.0);
	  	glVertex2f(x1+t1,y11+t2);
	  	glVertex2f(x2+t1,y11+t2);
	  	glVertex2f(x2+t1,y2+t2);
	  	glVertex2f(x1+t1,y2+t2);
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
	
	printf("\n\n Translation Point's: \n\n");
	printf("Enter the values of T1 - ");
	scanf("%f",&t1);
	printf("Entter the values of T2 - ");
	scanf("%f",&t2);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(800,1000);
          glutInitWindowPosition(0,0);
	glutCreateWindow("Translation");
	glutDisplayFunc(display);
	init();
	glutMainLoop(); 
	
	return 0;
}

