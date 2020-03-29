#pragma once

#include <vector>
#include <string>
#include "Vertex.h"

using namespace std;

class Edge
{
public:
	string label;
	vector<Vertex> vertices;

	Edge(string name, vector<Vertex> vertices);
;};

