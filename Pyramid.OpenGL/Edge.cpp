#include "Edge.h"

Edge::Edge(string name, vector<Vertex> vertices)
{
	this->label = name;

	vector<Vertex> copyVertices(vertices);
	this->vertices = copyVertices;
}
