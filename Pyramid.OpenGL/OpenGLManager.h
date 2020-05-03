#ifndef OPENGL_MANAGER_H

#include "Shape3D.h"

class OpenGLManager
{
public:
	void initialize();
	void window(int argc, char** argv, const char *title);
	void display(Shape3D *shape3d);
	void reshape(GLsizei width, GLsizei height);
};

#endif // !OPENGL_MANAGER_H
