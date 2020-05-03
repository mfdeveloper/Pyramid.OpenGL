#ifndef FILE_OFF_H
#define FILE_OFF_H

#include <string>
#include <vector>
#include <list>
#include <map>
#include "Vertex.h"

class FileOff
{
public:
	std::list<std::string> lines;
	std::vector<Vertex*> vertices;

	std::string getCurrentDir();
	FileOff* load(std::string path);
	std::vector<std::string> getData();
	int getCountVertex();
	int getCountEdges();
	int getCountFaces();
	bool exists(std::string path);
	bool isValid();

protected:
	std::vector<std::string> vectorLines;
	std::map<std::string, int> countElements;
};

#endif // !FILE_OFF_H
