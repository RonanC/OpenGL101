// Lab1-Basics.cpp : main project file.

//#include "stdafx.h"
#include <StdAfx.h>
#include <windows.h>	// Standard Header for Most Programs
#include <GL/GL.h>		// The GL Header File
#include <GL/glut.h>	// The GL Utility Toolkit <Glut) Header

void display (void);

void init (GLvoid){
	glShadeModel(GL_SMOOTH);			// enable flat shading (GL_FLAT each model has one colour, GL_SMOOTH mixes colours)
	glClearColor(1.0, 1.0, 1.0, 1.0);	// yellow  background			// RGB + Alpha
	glColor3f(0.0, 1.0 , 0.0);			// 3 floating point numbers
}

void reshape(int w, int h){			// create the reshape function    / This projects the spacial image onto the window on your monitor), when we rezie our window this takes effect and changres teh shape accordingly
	float ar; // aspect ratio
	ar = (float) h /(float) w;		// aspect ratio
	// h/w == * Y
	// w/h == * X

	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);	// select the projection matric to identity
	glLoadIdentity();				// reset the projection matrix to identity
	//gluOrtho2D(-2.0, 2.0,-2.0*ar, 2.0*ar);	// calculate new projection matrix
	gluOrtho2D(-6.0, 6.0,-6.0*ar, 6.0*ar);	// this is like getting the graph paper ready
	// graphic language utility = GLU
	// The different between x and y must be the same number of units
}

void main (int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);	// display mode
	glutInitWindowSize(500, 500);		// set initial window size
	glutCreateWindow("Triangle");		// window title
	glutDisplayFunc(display);	
	glutReshapeFunc(reshape);
	init();
	glutMainLoop();				// Initialize the main loop
}

// 1a - GL_TRIANGLES
void aTri(void){
	// 1b: green triangle
	// glColor3f(0.0, 1.0 , 0.0);

	glBegin(GL_TRIANGLES);			// Drawing using triangles
	// vertex -> point, change ceratin point colours in order to mix.smooth colours
		glColor3f(1.0, 0.0 , 0.0);
		glVertex2f(0.0,1.0);			// top

		glColor3f(0.0, 1.0 , 1.0);
		glVertex2f(-1.0,-1.0);			// bottom left

		glColor3f(0.0, 1.0 , 0.0);
		glVertex2f(1.0,-1.0);			// bottom right
	glEnd();						// finished drawing the triangle
}

// 1b - GL_LINE_LOOP
void lineloop(void){
		glLineWidth(2);
		glColor3f(1.0, 0.0 , 1.0);	// magenta border

		glBegin(GL_LINE_LOOP);
				glVertex2f(0.0,1.0);			// top
				glVertex2f(-1.0,-1.0);			// bottom left
				glVertex2f(1.0,-1.0);			// bottom right
		glEnd();
}

// Draw Axes
void drawAxes(void){
	glColor3f(0,0,0);

	glBegin(GL_LINES);
		glVertex2f(-5.0, 0.0);	// x axis
		glVertex2f(5.0, 0.0);	// x axis

		glVertex2f(0.0, -4.0);	// y axis
		glVertex2f(0.0, 4.0);	// y axis
	glEnd();
}

// 1d - glTranslate
void translation(void){
	glColor3f(0,0,0);
	glBegin(GL_TRIANGLES);
		glVertex2f(1,1);
		glVertex2f(2,3);
		glVertex2f(4,3);
	glEnd();

	glTranslatef(3,-2, 0);
	glColor3f(1,1,1);
	glBegin(GL_TRIANGLES);
		glVertex2f(1,1);
		glVertex2f(2,3);
		glVertex2f(4,3);
	glEnd();
}

// test1
void test1(void){
	glColor3f(0.0, 0.0 , 1.0);
	glBegin(GL_TRIANGLES);		
		glVertex2f(0.0,0.5);			
		glVertex2f(-0.5,-0.75);			
		glVertex2f(0.5,-0.75);			
		glColor3f(1.0, 0.0 , 0.0);	
	glEnd();	

	glLineWidth(1);

	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(-1, 0);
		glVertex2f(5, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glVertex2f(0, -3);
		glVertex2f(0, 8);
	glEnd();
}

// 1e - quadrangle
void quadrangle(void){
	glColor3f(0,0,0);
	//glClearColor(1.0, 1.0, 1.0, 1.0);	// RGB + Alpha

	glBegin(GL_LINE_LOOP);	// draw outline
		glVertex2f(1,1);
		glVertex2f(4,-1);
		glVertex2f(4,1);
		glVertex2f(2,2);
	glEnd();

	glTranslatef(3,1,0);	// translates

	glBegin(GL_LINE_LOOP);	// draw outline
		glVertex2f(1,1);
		glVertex2f(4,-1);
		glVertex2f(4,1);
		glVertex2f(2,2);
	glEnd();
}
/* ROTATION:

glRotatef(P,x,y,z);
p == peta

glRotatef(-50,0,0,1)

Use the right hand rule*/

// 1f - GL_ROTATE
void rotate(void){
	glBegin(GL_LINE_LOOP);
		glVertex2f(1,1);
		glVertex2f(2,3);
		glVertex2f(4,3);
	glEnd();

	glRotatef(-50,0,0,1);	// x,y,z,?

	glBegin(GL_LINE_LOOP);
		glVertex2f(1,1);
		glVertex2f(2,3);
		glVertex2f(4,3);
	glEnd();
}

// 1g - rotate 130 degrees
void rotate2(void){
	glBegin(GL_LINE_LOOP);
		glVertex2f(1,1);
		glVertex2f(4,-1);
		glVertex2f(4,1);
		glVertex2f(2,2);
	glEnd();

	glRotatef(130,0,0,1);

	glBegin(GL_LINE_LOOP);
		glVertex2f(1,1);
		glVertex2f(4,-1);
		glVertex2f(4,1);
		glVertex2f(2,2);
	glEnd();
}

// 1hi - rotation, translation
void rottran(void){
	glBegin(GL_LINE_LOOP);
		glVertex2f(0,0);
		glVertex2f(0,1);
		glVertex2f(1,1);
	glEnd();

	glRotatef(-90,0,0,1);

	glTranslatef(2,0,0);

	glBegin(GL_LINE_LOOP);
		glVertex2f(0,0);
		glVertex2f(0,1);
		glVertex2f(1,1);
	glEnd();
}

// 1hii - translation, rotation
void tranrot(void){
	glBegin(GL_LINE_LOOP);
		glVertex2f(0,0);
		glVertex2f(0,1);
		glVertex2f(1,1);
	glEnd();

	glTranslatef(2,0,0);

	glRotatef(-90,0,0,1); // r,x,y,a

	glBegin(GL_LINE_LOOP);
		glVertex2f(0,0);
		glVertex2f(0,1);
		glVertex2f(1,1);
	glEnd();
}

// 1i: rotation about origin(1-1)
void rotorigin(void){
		glBegin(GL_LINE_LOOP);
			glVertex2f(1,2);
			glVertex2f(3,-1);
			glVertex2f(2,3);
		glEnd();

		glTranslatef(1,-1,0);	
		glRotatef(70,0,0,1);		// Peta, 0, 0, 1		// rotating about the z axis
		glTranslatef(-1,1,0);						

		glBegin(GL_LINE_LOOP);
			glVertex2f(1,2);
			glVertex2f(3,-1);
			glVertex2f(2,3);
		glEnd();
	}

// 1j: rotation about origin
void rotorigin2(void){
	glBegin(GL_LINE_LOOP);
		glVertex2f(1,3);
		glVertex2f(3,0);
		glVertex2f(5,1);
		glVertex2f(3,3);
	glEnd();

	glTranslatef(-1,2,0);
	glRotatef(-100,0,0,1);
	glTranslatef(1,-2,0);

	glBegin(GL_LINE_LOOP);
		glVertex2f(1,3);
		glVertex2f(3,0);
		glVertex2f(5,1);
		glVertex2f(3,3);
	glEnd();

}


// 1k: multmatrix
void multmatrix(void){
	// a mutlimatric is a reflection

	// theta is 80, 2 thetha is 160
	float ro[16] = {-0.940, 0.342, 0, 0, 0.342, -0.940, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};

	glBegin(GL_LINE_LOOP);
		glVertex2f(2,3);
		glVertex2f(3,0);
		glVertex2f(5,1);
	glEnd();

	glTranslatef(1, -2,0);
	//glRotatef(80,0,0,1);
	glMultMatrixf(ro);
		// rotation is cos theta
		// multiMatrix is cos 2 theta, this is how we do a reflection
	glTranslatef(-1, 2,0);

	glBegin(GL_LINE_LOOP);
		glVertex2f(2,3);
		glVertex2f(3,0);
		glVertex2f(5,1);
	glEnd();
}

// 1l: reflection 2
void reflection(void){
	float ro[16] = {-0.866, 0.5, 0, 0, 
					0.5, 0.866, 0, 0,
					 0, 0, 1, 0, 
					 0, 0, 0, 1};

	glBegin(GL_LINE_LOOP);
		glVertex2f(2,2);
		glVertex2f(3,2);
		glVertex2f(4,1);
		glVertex2f(1,-2);
	glEnd();

	glTranslatef(2,3,0);
	glMultMatrixf(ro);
	glTranslatef(-2,-3,0);

	glBegin(GL_LINE_LOOP);
		glVertex2f(2,2);
		glVertex2f(3,2);
		glVertex2f(4,1);
		glVertex2f(1,-2);
	glEnd();
}

// 1m: reflection & rotation
void refrot(void){	// to the positive x axis
	// sin(-140) = -0.643
	// cos(-140) = -0.766

	float ro[16] = {-0.766, -0.643, 0, 0,
					-0.643, 0.766, 0, 0,
					0, 0, 1, 0,
					0, 0, 0, 1};

	glBegin(GL_LINE_LOOP);
		glVertex2f(3,2);
		glVertex2f(1,1);
		glVertex2f(2,-2);
	glEnd();

	glTranslatef(1,-1,0);
	glMultMatrixf(ro);
	glTranslatef(-1,1,0);

	glBegin(GL_LINE_LOOP);
		glVertex2f(3,2);
		glVertex2f(1,1);
		glVertex2f(2,-2);
	glEnd();

	glLoadIdentity();

	// continue from (ii)

	glTranslatef(0,-1,0);
	glRotatef(80,0,0,1);
	glTranslatef(-0,1,0);

	glBegin(GL_LINE_LOOP);
		glVertex2f(3,2);
		glVertex2f(1,1);
		glVertex2f(2,-2);
	glEnd();
}

void display (void){
	glClear(GL_COLOR_BUFFER_BIT);	// clear the display function

	//these 2 commands resets the axil system
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glColor3f(0,0,0);
	glLineWidth(2);

	drawAxes();

// 1e - quadrangle
	//quadrangle();

// 1f - GL_ROTATE
	//rotate();

// 1g - rotate 130 degrees
	//rotate2();

// 1hi/ii - translation/rotation
	//rottran();
	//tranrot();

// 1i: rotation about origin(1-1)
	//rotorigin();

// 1j: rotation about origin
	//rotorigin2();

// 1k: multmatrix
	//multmatrix();

// 1l: reflection 2
	//reflection();

// 1m: reflection & rotation
	refrot();


	glFinish();						// put all above pending ops into effect
}