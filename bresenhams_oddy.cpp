/*#include <GL/glut.h>
#include<iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

void Circle(int,int,int);
   int Xc,Yc,r;

   void draw()
   {
   	Circle(Xc,Yc,r);
   	Circle(Xc+(2*r-6),Yc,r);
   	Circle(Xc+(4*r-12),Yc,r);
   	Circle(Xc+(6*r-18),Yc,r);
   	glEnd();
   	glFlush();
   }
   
void init()
{
  glClearColor(0.0,0.0,1.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glPointSize(3.0);
  gluOrtho2D(0.0,500,0.0,500);
}

void PutPixel(GLint x,GLint y)
{
  glBegin(GL_POINTS);
     glVertex2i(x,y);
  
}

void Circle(int x_center,int y_center,int r){
  int x=0,y=r;
  int Di = 3/2 - r; 
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f( 5 ,5, 5);
  while(x<=y)

{
    PutPixel(x_center+x,y_center+y);
    PutPixel(x_center+y,y_center+x);
    PutPixel(x_center-x,y_center+y);
    PutPixel(x_center+y,y_center-x);
    PutPixel(x_center-x,y_center-y);
    PutPixel(x_center-y,y_center-x);
    PutPixel(x_center+x,y_center-y);
    PutPixel(x_center-y,y_center+x);

   if (Di<0)
   Di += (2*x)+3;
   else {
   Di += (2*(x-y))+5;
   y -= 1;
    }
    x++;
  }
 
}

int main(int argc,char **argv)
{
	
	
   cout<<"Enter the centre point Xc:";
   cin>>Xc;
   cout<<"Enter the centre point Yc:";
   cin>>Yc;
   cout<<"Enter radius:";
   cin>>r;
   
   
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Bresenham Circle");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}*/


