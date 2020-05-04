#ifndef FILEOFF_RENDER_H

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "Shape3D.h"
#include "FileOff.h"

class FileOffRender : public Shape3D
{
public:

	FileOff* fileOff;

	FileOffRender() : fileOff(nullptr) {};
	FileOffRender(FileOff* file) : fileOff(file) {};

	/*
		Render a object in a OpenGL window
	*/
	virtual void draw();
};

#endif // !FILEOFF_RENDER_H
