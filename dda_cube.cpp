

/**/
#include <iostream>			// Include I/O library
	#include <cmath>            // Include math library
	#include <GL/glut.h>		// Include GLUT library
	#include <GL/gl.h>			// Include GL library

	using namespace std;

	void LineDDA(GLdouble,GLdouble,GLdouble,GLdouble);

		GLdouble x, y;


	GLfloat round_value( GLfloat v )
	{
		return floor( v + 0.5 );
	}


	void Draw_House()
	{

		glClear(GL_COLOR_BUFFER_BIT);		// Clear color buffer

		glBegin(GL_POINTS);		// Begin drawing the color line with points


	LineDDA(x,y,x+100,y-50);
	LineDDA(x+100,y-50,x+200,y);
	LineDDA(x+200,y,x+100,y+50);
	LineDDA(x+100,y+50,x,y);
	
	LineDDA(x,y,x,y-150);
	LineDDA(x,y-150,x+100,y-200);
	LineDDA(x+100,y-200,x+200,y-150);
	LineDDA(x+200,y-150,x+200,y);

	LineDDA(x+100,y-50,x+100,y-200);
	glEnd();
	glFlush();
	
	
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

			glVertex2d(x, y);		//Draw initial point

			for( int k = 0; k < steps; k++ )
				{
					x += xInc;	// increase x point
					y += yInc;	// increase y point

					glVertex2d( round_value(x), round_value(y) );	// Draw new Coordinates
				}

	}

	void Init()
	{

			glClearColor(0.0,0.0,1.0,0);	// Set background color to blue

			glColor3f(0.0,1.0,0.0);			// Set line color to Green

			glPointSize(4.0);				// Set point size to 8.0

			gluOrtho2D(0 , 700 , 0 , 700);	// Initiate coordinate system for given window
}

	int main(int argc, char **argv)
	{

			cout<<"\n************************************";
			cout<<"\nEnter Point1( X1 , Y1):\n";
			cin>>x>>y;
		

			glutInit(&argc,argv);							// Initialize GLUT
			glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	// Enable single buffered mode
			glutInitWindowPosition(0,0);					// Position the window's initial top-left corner
			glutInitWindowSize(640,480);					// Set the window's initial width & height
			glutCreateWindow("DDA Cube");	// Create window with the given title
			Init();		 									// Our own OpenGL initialization
			glutDisplayFunc(Draw_House);					// Register callback handler for window re-paint event
			glutMainLoop();									// Enter the infinite event-processing loop
return 0;
	}
/**/
