#ifndef SHAPE3D_H

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include <GL/freeglut.h>

class Shape3D
{
public:
	/*
		The camera positions
	*/
	float xPos;
	float yPos;
	float zPos;

	Shape3D(float x, float y) : xPos(x), yPos(y), zPos(5.0f), rotSpeed(2.0f) {};
	Shape3D(float x, float y, float z) : xPos(x), yPos(y), zPos(z), rotSpeed(2.0f) {};
	Shape3D() : Shape3D(0, 0, 5.0f) {};

	/*
	Make a virtual destructor in case we delete a pointer 
	of child of this class, so the proper derived destructor is called
	*/
	virtual ~Shape3D(){}

	GLfloat getRotationValue();
	GLfloat getRotationSpeed();
	void setRotation(GLfloat value);
	void incrementRotation();
	void setRotationSpeed(GLfloat speed);

	virtual void draw() = 0;

protected:

	/*
		The rotation matrix takes in a GLfloat.
		GLfloat is basically just a float, but
		defined by OpenGL.
	*/
	GLfloat rot = 0;

	/*
	 Just to make sure our speed can multiply with our
	 "rot" variable, we'll make this a GLfloat, too.
	*/
	GLfloat rotSpeed;
};

#endif // !SHAPE3D_H
