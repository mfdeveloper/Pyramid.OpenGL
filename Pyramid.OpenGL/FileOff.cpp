#include <iostream>
#include <stdexcept>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include "FileOff.h"
#include "Point.h"

namespace fs = boost::filesystem;
using namespace boost::algorithm;
using namespace std;

string FileOff::getCurrentDir()
{
	fs::path pathObj = fs::current_path();

	// The cli executable file (.exe) returns from "x64/Release" folder
	// Go back to the root project dir

	//TODO: Verify if this method is called from
	//cli or test project
	return pathObj.parent_path().parent_path().string();
}

FileOff* FileOff::load(string path)
{

	fs::fstream file;

	bool fileExists = this->exists(path);

	if (fileExists)
	{
		file.open(path);

		if (file.is_open())
		{
			string line;
			int i = 0;
			char verticeLetter = 'A';

			while (getline(file, line))
			{

				// Ignore commented or blank lines
				if (boost::regex_match(line, exprComment) || line.empty())
				{
					continue;
				}

				if (boost::regex_match(line, exprFileType))
				{
					lines.push_back(line);
				}

				if (boost::regex_match(line, exprCounts))
				{
					vector<string> countValues;

					split(countValues, line, is_space());

					if (!countValues.empty())
					{
						countElements["vertex"] = stoi(countValues[0]);
						countElements["faces"] = stoi(countValues[1]);
						countElements["edges"] = stoi(countValues[2]);

						lines.push_back(line);
					}
				}

				// Vertices points
				if (vertices.size() <= countElements["vertex"] && boost::regex_match(line, exprVerticesCoords))
				{
					string label = "Vertex.";
					vector<string> coordsValues;

					trim_left(line);
					line = boost::regex_replace(line, exprNormalizeSpaces, " ");

					split(coordsValues, line, is_space());

					if (!coordsValues.empty())
					{
						float x = stof(coordsValues[0]);
						float y = stof(coordsValues[1]);
						float z = stof(coordsValues[2]);

						/*
							Is the same to do "label.push_back(verticeLetter)"
							just like push a new value to a vector
						*/
						label += verticeLetter;
						Vertex* vertex = new Vertex(label, new Point(x, y, z));
						vertices.push_back(vertex);
					}

					verticeLetter++;
				}

				// Faces points
				if (faces.size() <= countElements["faces"] && boost::regex_match(line, exprFaces))
				{
					vector<string> faceVertices;

					trim_left(line);
					line = boost::regex_replace(line, exprNormalizeSpaces, " ");
					split(faceVertices, line, is_space());

					if (!faceVertices.empty())
					{

						Face* face = new Face("Facexx");
						int totalVertices = stoi(faceVertices[0]);

						for (int i = 1; i <= totalVertices; i++)
						{
							int vertexIndex = stoi(faceVertices[i]);
							Vertex* vertex = vertices[vertexIndex];

							// Avoid replace an existent color
							if (vertex->color == nullptr)
							{
								vector<string> colorValues(faceVertices.begin() + totalVertices + 1, faceVertices.end());
								vertex->color = new Color(colorValues);
							}
							
							verticesIndex.push_back(vertexIndex);

							face->vertices.push_back(vertex);
						}

						faces.push_back(face);
					}
				}

				std::cout << line << '\n';
				i++;
			}

			file.close();
			verticeLetter = 'A';

			if (vertices.size() != countElements["vertex"])
			{
				throw std::runtime_error("[VertexCountError]: The total of vertices is not equal to all vertices coordinates lines");
			}
		}
		else if (file.fail())
		{
			printf("Error to open file %s. Verify if the file exists", ".off");
		}
	}

	vectorLines.assign(lines.begin(), lines.end());
	loaded = true;
	return this;
}

bool FileOff::exists(string path)
{
	fs::path p(path);

	return fs::exists(p);
}

bool FileOff::isValid()
{
	if (!vectorLines.empty() && vectorLines.at(0) == "OFF")
	{
		return true;
	}

	return false;
}

bool FileOff::isLoaded()
{
	return (loaded && vertices.size() > 0 && faces.size() > 0);
}

vector<string> FileOff::getData()
{
	return !vectorLines.empty() ? vectorLines : vector<string>();
}

int FileOff::getCountVertex()
{
	return countElements["vertex"];
}

int FileOff::getCountEdges()
{
	return countElements["edges"];
}

int FileOff::getCountFaces()
{
	return countElements["faces"];
}
