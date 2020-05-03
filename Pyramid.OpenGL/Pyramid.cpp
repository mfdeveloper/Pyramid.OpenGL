#include <algorithm>
#include "Pyramid.h"

using namespace std;

void Pyramid::draw()
{
    // We're telling OpenGL that we want to render triangles.
    glBegin(GL_TRIANGLES);

    for (Edge* edge : edges) {

        if (edge->vertexOrigin != NULL)
        {
            if (!isDrawnVertex(edge->label, edge->vertexOrigin))
            {

                if (edge->vertexOrigin->color != NULL)
                {
                    glColor3f(edge->vertexOrigin->color->red, edge->vertexOrigin->color->green, edge->vertexOrigin->color->blue);
                }
                else {
                    glColor3f(1.0f, 0.0f, 0.0f);
                }

                glVertex3f(edge->vertexOrigin->point->x, edge->vertexOrigin->point->y, edge->vertexOrigin->point->z);

                renderedVertices.push_back(edge->vertexOrigin->label);
            }
        }

        if (edge->vertexDestiny != NULL)
        {
            if (!isDrawnVertex(edge->label, edge->vertexDestiny))
            {

                if (edge->vertexDestiny->color != NULL)
                {
                    glColor3f(edge->vertexDestiny->color->red, edge->vertexDestiny->color->green, edge->vertexDestiny->color->blue);
                }
                else {
                    glColor3f(1.0f, 0.0f, 0.0f);
                }

                glVertex3f(edge->vertexDestiny->point->x, edge->vertexDestiny->point->y, edge->vertexDestiny->point->z);

                renderedVertices.push_back(edge->vertexDestiny->label);
            }
        }

    }

    // Clean rendered vertices vector to avoid draw errors in OpenGL loop
    renderedVertices.erase(renderedVertices.begin(), renderedVertices.end());

    glEnd();
}

bool Pyramid::isDrawnVertex(string edgeLabel, Vertex * vertexToCompare)
{

    if (find(renderedVertices.begin(), renderedVertices.end(), vertexToCompare->label) != renderedVertices.end())
    {
        return true;
    }

    return false;
}
