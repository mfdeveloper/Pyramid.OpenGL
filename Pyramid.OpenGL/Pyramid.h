#pragma once
#include <GL/freeglut.h>
#include <vector>
#include "Point.h"
#include "Vertex.h"
#include "Edge.h"
#include "Face.h"
#include "Color.h"

class Pyramid
{

	public:

		/*
		 The rotation matrix takes in a GLfloat.
		 GLfloat is basically just a float, but
		 defined by OpenGL.
		*/
		GLfloat rot;

		/*
		 Just to make sure our speed can multiply with our
         "rot" variable, we'll make this a GLfloat, too.
		*/
		GLfloat rotSpeed;

		/*
			The camera positions
		*/
		float xPos;
		float yPos;
		float zPos;

		vector<Face> faces;

		Pyramid();

		void initOpenGL();
		void createWinged();

		/*
		 Render a object in a OpenGL window
		*/
		void draw(bool run);
		void drawWinged();
		void drawRaw();

};

