/*#include<GL/glut.h>
#include <GL/gl.h>
   #include <iostream>
   #include <math.h>

   using namespace std;
	void draw(int,int,int);
   int Xc,Yc;
   int r;
void draw(int Xc,int Yc,int r)
{
	float start_x,start_y,x1,y1,x2,y2,e;
   int i,val;

   start_x=r;
   start_y=0;

   x1=start_x;
   y1=start_y;
   i=0;
   do
   {
       val=pow(2,i);
        i++;
  }while(val<r);
   e=1/pow(2,i-1);

  do
  {
  x2 = x1 + e*y1;
  y2 = y1 - e*x2;
  glBegin(GL_POINTS);
  glVertex2f(Xc+x2,Yc-y2);
  x1=x2;
  y1=y2;
  glEnd();
  }while((y1 - start_y) < e ||(start_x - x1) > e);
  glFlush();
}

   void display()
   {
   	
   	   //glClearColor(1.0,1.0,1.0,1.0);

glColor3f(0.0,0.0,1.0);
draw(Xc,Yc,r);

glColor3f(1.0,1.0,1.0);
draw(Xc+(2*r+5),Yc,r);

glColor3f(1.0,0.0,0.0);
draw(Xc+(4*r+10),Yc,r);

glColor3f(1.0,1.0,0.0);
//draw(Xc+22,Yc-r,r);
draw((Xc+Xc+(2*r+5))/2,Yc-r,r);

glColor3f(0.0,1.0,0.0);
//draw((Xc+22)+(2*r+4),Yc-r,r);
draw(((Xc+(2*r+5)) + (Xc+(4*r+10)))/2,Yc-r,r);

  }

  void init()
  {
   glClear(GL_COLOR_BUFFER_BIT);
   //glClearColor(1.0,1.0,1.0,1.0);
   glPointSize(3.0);
   gluOrtho2D(0,640,0,480);

   }

   int main(int argc,char **argv)
   {


   cout<<"Enter the centre point Xc:";
   cin>>Xc;
   cout<<"Enter the centre point Yc:";
   cin>>Yc;
   cout<<"Enter radius:";
   cin>>r;

   glClear(GL_COLOR_BUFFER_BIT);
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(640,480);
   glutInitWindowPosition(0,0);
   glutCreateWindow("DDA Circle");
   init();
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
   }
   */
