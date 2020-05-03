#include "Shape3D.h"

GLfloat Shape3D::getRotationValue()
{
	return rot;
}

GLfloat Shape3D::getRotationSpeed()
{
	return rotSpeed;
}

void Shape3D::setRotation(GLfloat value)
{
	rot = value;
}

void Shape3D::incrementRotation()
{
	rot += 0.1f;
}

void Shape3D::setRotationSpeed(GLfloat speed)
{
	rotSpeed = speed;
}
