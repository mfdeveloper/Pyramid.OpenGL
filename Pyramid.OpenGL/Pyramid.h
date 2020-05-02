#ifndef PYRAMID_H
#define PYRAMID_H

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include <GL/freeglut.h>
#include <vector>
#include <map>
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

		std::vector<Face *> faces;
		std::vector<Edge *> edges;

		Pyramid();

		void createWinged();

		/*
		 Render a object in a OpenGL window
		*/
		void draw(bool run);
		void drawWinged();
		void drawRaw();

private:
	std::vector<std::string> renderedVertices;
	bool isDrawnVertex(std::string edgeLabel, Vertex* verticeToCompare);
};

#endif // !PYRAMID_H
