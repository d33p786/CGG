/*
Name:Deepak Chaudhari
Block:B4
Roll No:SCETTYB428
*/

/**
#include<GL/freeglut.h>
#include<GL/gl.h>
#include<cmath>
#include<stdio.h>
#include<iostream>



using namespace std;

GLdouble tx,ty,nx1,ny1,nx2,ny2,nx3,ny3,t,r;            
 GLfloat round_value( GLfloat v )
{              
    return floor( v + 0.5 );
}              

 void LineDDA( GLdouble X1, GLdouble Y1, GLdouble X2, GLdouble Y2 )
 {
    GLdouble dx = ( X2 - X1 );
    GLdouble dy = ( Y2 - Y1 );
    GLdouble steps;
    steps = ( abs(dx) > abs(dy) ) ? ( abs(dx) ) : ( abs(dy) );
    GLfloat xInc, yInc;
    xInc = dx / (GLfloat)steps;
    yInc = dy / (GLfloat)steps;
    GLfloat x, y;
    x = X1;
    y = Y1;
    glVertex2d(x, y);               
    for( int k = 0; k < steps; k++ )
    {
        x += xInc;     
        y += yInc;     
        glVertex2d( round_value(x), round_value(y) );   
    }
 }

void init()
{
    glClearColor(0.0,0.0,0.0,0);   
    glColor3f(1.0,1.0,1.0);                 
    glPointSize(2.0);                               
    gluOrtho2D(0 , 640 , 0 , 480); 
}

void trans(GLdouble tx,GLdouble ty)
{
    glColor3f(1.0,0.0,0.0);
    LineDDA(20+tx,160+ty,100+tx,160+ty);
    LineDDA(20+tx,80+ty,100+tx,80+ty);
    LineDDA(20+tx,80+ty,20+tx,160+ty);
    LineDDA(100+tx,160+ty,100+tx,80+ty);
    t=3.14*r/180;
    nx1=abs(x1*cos(t)-y1*sin(t));
    ny1=abs(x1*sin(t)+y1*cos(t));
    nx2=abs(x2*cos(t)-y2*sin(t));
    ny2=abs(x2*sin(t)+y2*cos(t));
    nx3=abs(x3*cos(t)-y3*sin(t));
    ny3=abs(x3*sin(t)+y3*cos(t));
    line(nx1,ny1,nx2,ny2);
    line(nx2,ny2,nx3,ny3);
    line(nx3,ny3,nx1,ny1);
    getch();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);           
    glBegin(GL_POINTS);             

    LineDDA(20,160,100,160);
    LineDDA(20,80,100,80);
    LineDDA(20,80,20,160);
    LineDDA(100,160,100,80);
    trans(tx,ty);
    glEnd();               
    glFlush(); 
}

int main(int argc,char** argv)
{
    printf("\n Enter the angle of rotation");
    scanf("%d",&r);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(720,480);
    glutCreateWindow("Translation");
    init();
    glutDisplayFunc(display);
    glutMainLoop();   
    return(0);
}
/**/
