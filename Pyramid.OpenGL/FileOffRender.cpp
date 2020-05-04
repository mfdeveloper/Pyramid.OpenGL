#include "FileOffRender.h"

void FileOffRender::draw()
{
	if (fileOff->isLoaded())
	{
		// We're telling OpenGL that we want to render rectangles.
		glBegin(GL_QUADS);

		for (Face * face : fileOff->faces) {

			for (Vertex* vertex : face->vertices) {

				if (vertex->color != nullptr)
				{
					glColor4f(
						vertex->color->red,
						vertex->color->green,
						vertex->color->blue,
						vertex->color->alpha
					);
				}

				glVertex3f(
					vertex->point->x,
					vertex->point->y,
					vertex->point->z
				);
			}
		}

		glEnd();
	}
}
