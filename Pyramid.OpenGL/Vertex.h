// winged-edge data structure
#ifndef VERTEX_H
#define VERTEX_H

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include <string>
#include "Point.h"
#include "Color.h"

class Vertex
{
public:

	std::string label;
	Point *point;
	Color *color;

	Vertex(std::string name, Point *point);
	Vertex(std::string name, Point *point, Color *color);
	~Vertex();
};

#endif // !VERTEX_H
