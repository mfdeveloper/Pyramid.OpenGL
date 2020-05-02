#ifndef EDGE_H
#define EDGE_H

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include <string>
#include "Vertex.h"
#include "Face.h"

class Edge
{
public:

	std::string label;

	// Vertices
	Vertex* vertexOrigin;
	Vertex* vertexDestiny;

	// Edges
	Edge* edgeLeftBack;
	Edge* edgeRightBack;
	Edge* edgeLeftNext;
	Edge* edgeRightNext;

	// Faces
	Face* faceLeft;
	Face* faceRight;

	Edge(std::string name);
};

#endif // !EDGE_H
