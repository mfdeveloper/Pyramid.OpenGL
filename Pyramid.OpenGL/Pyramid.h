#ifndef PYRAMID_H
#define PYRAMID_H

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include <GL/freeglut.h>
#include <vector>
#include "Shape3D.h"
#include "Vertex.h"
#include "Edge.h"
#include "Face.h"

class Pyramid: public Shape3D
{

	public:

		std::vector<Face *> faces;
		std::vector<Edge *> edges;

		/*
		 Render a object in a OpenGL window
		*/
		virtual void draw();

private:
	std::vector<std::string> renderedVertices;
	bool isDrawnVertex(std::string edgeLabel, Vertex* verticeToCompare);
};

#endif // !PYRAMID_H
