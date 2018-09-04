#include <GL/glut.h>
   #include <GL/gl.h>
   #include <iostream>
   #include <math.h>

   using namespace std;

   int Xc,Yc;
   int r;

   void display()
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

  void init()
  {
   glClear(GL_COLOR_BUFFER_BIT);
   glClearColor(1.0,1.0,1.0,1.0);
   glColor3f(0.0,1.0,0.0);
   gluOrtho2D(0,640,0,480);

   }

   int main(int argc,char **argv)
   {


   cout<<"Enter the center point Xc:";
   cin>>Xc;
   cout<<"Enter the center point Yc:";
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
