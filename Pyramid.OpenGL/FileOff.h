#ifndef FILE_OFF_H
#define FILE_OFF_H

#include <string>
#include <vector>
#include <list>
#include <map>
#include <boost/regex.hpp>
#include "Color.h"
#include "Vertex.h"
#include "Face.h"

class FileOff
{
public:
	std::list<std::string> lines;
	std::vector<Vertex*> vertices;
	std::vector<int> verticesIndex;
	std::vector<Face*> faces;

	std::string getCurrentDir();
	FileOff* load(std::string path);
	std::vector<std::string> getData();
	int getCountVertex();
	int getCountEdges();
	int getCountFaces();
	bool exists(std::string path);
	bool isValid();
	bool isLoaded();

protected:
	std::vector<std::string> vectorLines;
	std::map<std::string, int> countElements;
	bool loaded = false;

	// Regex expressions
	boost::regex exprFileType{ "^OFF$" };
	boost::regex exprComment{ "(^#)|(//)" };
	boost::regex exprCounts{ "(\\d+)\\s(\\d+)\\s(\\d+)" };
	boost::regex exprVerticesCoords{ "^\\s+(-?\\d+)\\.(\\d+)\\s+(-?\\d+)\\.(\\d+)\\s+(-?\\d+)\\.(\\d+)" };
	boost::regex exprFaces{ "^\\s+(\\d+)\\s\\s[\\d\\s\\d]+\\s+(\\d+)\\.(\\d+)\\s+(\\d+)\\.(\\d+)\\s+(\\d+)\\.(\\d+)\\s+\\d+\\.\\d+" };
	boost::regex exprNormalizeSpaces{ "\\s+" };
};

#endif // !FILE_OFF_H
