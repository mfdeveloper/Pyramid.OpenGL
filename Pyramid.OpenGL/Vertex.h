#pragma once
// winged-edge data structure

#include <string>
#include "Point.h"
#include "Color.h"

using namespace std;

class Vertex
{
public:
	string label;
	Point *point;
	Color *color;
	Vertex(string name, Point *point);
	Vertex(string name, Point* point, Color* color);
	~Vertex();

private:

};