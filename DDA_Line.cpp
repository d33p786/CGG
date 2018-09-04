/* Program : Draw a line using DDA Line Drawing algorithm.
 *
 * Name : Deepak Chaudhari
 *
 * Roll No. : SCETTYB428
 *
 */

	#include <iostream>			// Include I/O library
	#include <cmath>            // Include math library
	#include <GL/glut.h>		// Include GLUT library
	#include <GL/gl.h>			// Include GL library

	using namespace std;

	/* Global Variables */

	GLdouble X1, Y1, X2, Y2;

	/* Function return rounded value */

	GLfloat round_value( GLfloat v )
	{
		return floor( v + 0.5 );
	}

	void LineDDA()
	{
			/* Calculate differences */

			GLdouble dx = ( X2 - X1 );
			GLdouble dy = ( Y2 - Y1 );

			/* Calculate steps */

			GLdouble steps;
			steps = ( abs(dx) > abs(dy) ) ? ( abs(dx) ) : ( abs(dy) );

			/* Calculate Increment factor in  X and Y */

			GLfloat xInc, yInc;
			xInc = dx / (GLfloat)steps;
			yInc = dy / (GLfloat)steps;

			/* Initialize starting position */

			GLfloat x, y;
			x = X1;
			y = Y1;


			glClear(GL_COLOR_BUFFER_BIT);		// Clear color buffer

			glBegin(GL_POINTS);		// Begin drawing the color line with points

			glVertex2d(x, y);		//Draw initial point

			for( int k = 0; k < steps; k++ )
				{
					x += xInc;	// increase x point
					y += yInc;	// increase y point

					glVertex2d( round_value(x), round_value(y) );	// Draw new Coordinates
				}

			glEnd();		// End Drawing

			glFlush();		 // Render now
	}

	/* Initialize OpenGL Graphics */

	void Init()
	{

			glClearColor(0.0,0.0,1.0,0);	// Set background color to blue

			glColor3f(0.0,1.0,0.0);			// Set line color to Green

			glPointSize(4.0);				// Set point size to 4.0

			gluOrtho2D(0 , 640 , 0 , 480 );	// Initiate coordinate system for given window
	}

	/* Main function */

	int main(int argc, char **argv)
	{

			cout<<"Enter two end points of the line to be drawn:\n";
			cout<<"\n************************************";
			cout<<"\nEnter Point1( X1 , Y1):\n";
			cin>>X1>>Y1;
			cout<<"\n************************************";
			cout<<"\nEnter Point1( X2 , Y2):\n";
			cin>>X2>>Y2;


			glutInit(&argc,argv);							// Initialize GLUT
			glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	// Enable single buffered mode
			glutInitWindowPosition(0,0);					// Position the window's initial top-left corner
			glutInitWindowSize(640,480);					// Set the window's initial width & height
			glutCreateWindow("DDA_Line_Drawing_Algorithm");	// Create window with the given title
			Init();		 									// Our own OpenGL initialization
			glutDisplayFunc(LineDDA);						// Register callback handler for window re-paint event
			glutMainLoop();									// Enter the infinite event-processing loop
			return 0;
	}


	/*
	 *
	 * OUTPUT:
	 *
	 *
		Enter two end points of the line to be drawn:

		************************************
		Enter Point1( X1 , Y1):
		100
		100

		************************************
		Enter Point1( X2 , Y2):
		400
		300

	 *
	 */
