#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Edge.h"

using namespace std;

class Face
{
public:
	string label;
	vector<Edge> edges;

	Face(string name, vector<Edge> edges);

};

