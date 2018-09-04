/* Program : Draw a Home pattern using DDA Line Drawing algorithm.
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

	void LineDDA(GLdouble,GLdouble,GLdouble,GLdouble);

	/* Global Variables */

		GLdouble X1, Y1, X2, Y2;


	/* Function return rounded value */

	GLfloat round_value( GLfloat v )
	{
		return floor( v + 0.5 );
	}

	/* Function to draw House */

	void Draw_House()
	{

		glClear(GL_COLOR_BUFFER_BIT);		// Clear color buffer

		glBegin(GL_POINTS);		// Begin drawing the color line with points

		//roof

		LineDDA(X1-40,Y1*2,X2+40,Y2*2);
		LineDDA(X1-40,Y1*2,(X2+X1)/2,(Y1*2)+50);
		LineDDA(X2+40,Y2*2,(X2+X1)/2,(Y1*2)+50);

		//walls
		LineDDA(X1,Y1,X1,Y1*2);
		LineDDA(X2,Y2,X2,Y2*2);

		//base
		LineDDA(X1,Y1,X2,Y2);

		//door
		LineDDA((X2+X1)/2-30,Y1+90,(X2+X1)/2+30,Y2+90);
		LineDDA((X2+X1)/2-30,Y1+90,(X2+X1)/2-30,Y1);
		LineDDA((X2+X1)/2+30,Y2+90,(X2+X1)/2+30,Y2);


		glEnd();		// End Drawing

		glFlush();		 // Render now

	}

	void LineDDA( GLdouble X1, GLdouble Y1, GLdouble X2, GLdouble Y2 )
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

			glVertex2d(x, y);		//Draw initial point

			for( int k = 0; k < steps; k++ )
				{
					x += xInc;	// increase x point
					y += yInc;	// increase y point

					glVertex2d( round_value(x), round_value(y) );	// Draw new Coordinates
				}

	}

	/* Initialize OpenGL Graphics */

	void Init()
	{

			glClearColor(0.0,0.0,1.0,0);	// Set background color to blue

			glColor3f(0.0,1.0,0.0);			// Set line color to Green

			glPointSize(8.0);				// Set point size to 8.0

			gluOrtho2D(0 , 640 , 0 , 480);	// Initiate coordinate system for given window
	}

	/* Main function */

	int main(int argc, char **argv)
	{

			cout<<"\nNOTE:  Enter points such that Y1=Y2.\n";
			cout<<"\nEnter two end points of the Base for house:\n";
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
			glutDisplayFunc(Draw_House);					// Register callback handler for window re-paint event
			glutMainLoop();									// Enter the infinite event-processing loop
			return 0;
	}



	/*
	 * OUTPUT:
	 *

		NOTE:  Enter points such that Y1=Y2.

		Enter two end points of the Base for house:

		************************************
		Enter Point1( X1 , Y1):
		200
		150

		************************************
		Enter Point1( X2 , Y2):
		400
		150

	 *
	 */
