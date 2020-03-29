#include "Face.h"

Face::Face(string name, vector<Edge> edges)
{
	this->label = name;
	this->edges = edges;
}
