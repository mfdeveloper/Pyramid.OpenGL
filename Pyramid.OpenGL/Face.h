#ifndef FACE_H
#define FACE_H

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include <vector>
#include <string>
#include "Vertex.h"

class Face
{
public:

	std::string label;
	std::vector<Vertex *> vertices;

	Face(std::string name);
	
};

#endif // !FACE_H
