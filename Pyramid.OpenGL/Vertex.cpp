#include "Vertex.h"

using namespace std;

Vertex::Vertex(string name, Point *point): color(nullptr)
{
	this->label = name;
	this->point = point;
}

Vertex::Vertex(string name, Point *point, Color *color)
{
	this->label = name;
	this->point = point;
	this->color = color;
}

Vertex::~Vertex()
{
}