#include "Pyramid.h"

Pyramid::Pyramid()
{
    rot = 0.0f;
    rotSpeed = 1.0f;

    xPos = 0.0f;
    yPos = 0.0f;
    zPos = 5.0f;

    // ------------- Vertices, Edges and Faces ------------
    createWinged();

}

void Pyramid::createWinged()
{
    Vertex vertexFrontA = Vertex("Front.A", new Point(0.0f, 1.0f, 0.0f), new Color(1.0f, 0.0f, 0.0f));
    Vertex vertexFrontB = Vertex("Front.B", new Point(-1.0f, -1.0f, 1.0f), new Color(0.0f, 1.0f, 0.0f));
    Vertex vertexFrontC = Vertex("Front.C", new Point(1.0f, -1.0f, 1.0f), new Color(0.0f, 0.0f, 1.0f));

    // Front
    vector<Vertex> vFrontA = { { vertexFrontA, vertexFrontB, vertexFrontC } };
    //vector<Vertex> vFrontB = { { vertexFrontC, vertexFrontA } };

    vector<Edge> edgesFront = { { Edge("Front.a", vFrontA) } };

    Face faceFront = Face("Front.1", edgesFront);
    faces.push_back(faceFront);

    //Right
    Vertex vertexRightA = Vertex("Right.A", new Point(0.0f, 1.0f, 0.0f), new Color(1.0f, 0.0f, 0.0f));
    Vertex vertexRightB = Vertex("Right.B", new Point(1.0f, -1.0f, 1.0f), new Color(0.0f, 1.0f, 0.0f));
    Vertex vertexRightC = Vertex("Right.C", new Point(1.0f, -1.0f, -1.0f), new Color(0.0f, 0.0f, 1.0f));

    vector<Vertex> vEdgeRightA = { { vertexRightA, vertexRightB, vertexRightC } };
    //vector<Vertex> vEdgeRightB = { {  vertexRightC, vertexRightA } };

    vector<Edge> edgesRight = { { Edge("Right.a", vEdgeRightA) } };

    Face faceRight = Face("Right.2", edgesRight);
    faces.push_back(faceRight);

    // Back
    Vertex vertexBackA = Vertex("Back.A", new Point(0.0f, 1.0f, 0.0f));
    Vertex vertexBackB = Vertex("Back.B", new Point(1.0f, -1.0f, -1.0f));
    Vertex vertexBackC = Vertex("Back.C", new Point(-1.0f, -1.0f, -1.0f));

    vector<Vertex> vEdgeBackA = { { vertexBackA, vertexBackB, vertexBackC } };
    //vector<Vertex> vEdgeBackB = { { vertexBackC, vertexBackA } };

    vector<Edge> edgesBack = { { Edge("Back.a", vEdgeBackA) } };
    Face faceBack = Face("Back.3", edgesBack);
    faces.push_back(faceBack);

    //Left
    Vertex vertexLeftA = Vertex("Left.A", new Point(0.0f, 1.0f, 0.0f), new Color(1.0f, 0.0f, 0.0f));
    Vertex vertexLeftB = Vertex("Left.B", new Point(-1.0f, -1.0f, -1.0f), new Color(0.0f, 1.0f, 0.0f));
    Vertex vertexLeftC = Vertex("Left.C", new Point(-1.0f, -1.0f, 1.0f), new Color(0.0f, 0.0f, 1.0f));

    vector<Vertex> vEdgeLeftA = { { vertexLeftA, vertexLeftB, vertexLeftC } };
    //vector<Vertex> vEdgeLeftB = { { vertexLeftC, vertexLeftA } };

    vector<Edge> edgesLeft = { { Edge("Left.a", vEdgeLeftA) } };
    Face faceLeft = Face("Left.4", edgesLeft);
    faces.push_back(faceLeft);

    //Bottom 1
    Vertex vertexBottom1A = Vertex("Bottom1.A", new Point(-1.0f, -1.0f, 1.0f), new Color(1.0f, 0.0f, 0.0f));
    Vertex vertexBottom1B = Vertex("Bottom1.B", new Point(1.0f, -1.0f, 1.0f), new Color(0.0f, 1.0f, 0.0f));
    Vertex vertexBottom1C = Vertex("Bottom1.C", new Point(-1.0f, -1.0f, -1.0f), new Color(0.0f, 0.0f, 1.0f));

    vector<Vertex> vEdgeBottom1A = { { vertexBottom1A, vertexBottom1B, vertexBottom1C } };
    //vector<Vertex> vEdgeBottom1B = { { vertexBottom1C, vertexBottom1A } };

    vector<Edge> edgesBottom1 = { { Edge("Bottom1.a", vEdgeBottom1A) } };
    Face faceBottom1 = Face("Bottom1.5", edgesBottom1);
    faces.push_back(faceBottom1);

    //Bottom 2
    Vertex vertexBottom2A = Vertex("Bottom2.A", new Point(-1.0f, -1.0f, -1.0f), new Color(1.0f, 0.0f, 0.0f));
    Vertex vertexBottom2B = Vertex("Bottom2.B", new Point(1.0f, -1.0f, -1.0f), new Color(0.0f, 1.0f, 0.0f));
    Vertex vertexBottom2C = Vertex("Bottom2.C", new Point(1.0f, -1.0f, 1.0f), new Color(0.0f, 0.0f, 1.0f));

    vector<Vertex> vEdgeBottom2A = { { vertexBottom2A, vertexBottom2B, vertexBottom2C } };
    //vector<Vertex> vEdgeBottom2B = { { vertexBottom2C, vertexBottom2A } };

    vector<Edge> edgesBottom2 = { { Edge("Bottom2.a", vEdgeBottom2A) } };
    Face faceBottom2 = Face("Bottom2.6", edgesBottom2);
    faces.push_back(faceBottom2);
}

void Pyramid::initOpenGL() {
    
    // Set background color to black and opaque
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Set background depth to farthest
    glClearDepth(1.0f);

    // Enable depth testing for z-culling
    glEnable(GL_DEPTH_TEST);

    // Set the type of depth-test
    glDepthFunc(GL_LEQUAL);

    // Enable smooth shading
    glShadeModel(GL_SMOOTH);

    // Nice perspective corrections
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Pyramid::draw(bool run)
{
    glMatrixMode(GL_PROJECTION);        // This sends our matrix operations to the
                                        // projection matrix stack. Essentially this is
                                        // manipulating our camera.

    glLoadIdentity();                   // Whenever we start to do things with matrices,
                                        // it seems like most tutorials load the Identity
                                        // matrix to reset everything, making sure we're
                                        // working with a clean slate.

    gluPerspective(45.0f, 640.0f / 480.0f, 0.1f, 100.0f);    // This is our Field of View.
                                                          // Our FOV value is 45, then we
                                                          // pass in our aspect ratio, and
                                                          // finally we give our near-plane
                                                          // and far-plane

    glMatrixMode(GL_MODELVIEW);         // This sends our matrix operations to the
                                        // modelview matrix stack.

    // We want to enable depth, otherwise our triangles will look really weird.
    // The PVR won't be able to tell what's supposed to be in front, and what
    // should be in the back.
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);


    while (run) {

        glMatrixMode(GL_MODELVIEW);

        // Now we need to clear both the color buffer AND the depth buffer when we
        // go to draw.
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        glLoadIdentity();                        // Load a blank matrix to work with

        gluLookAt(xPos, yPos, zPos,                // This is essentially our camera
            0, 0, 0,
            0, 1, 0);

        // Our transformations for our pyramid
        glTranslatef(0.0f, 0.0f, -1.0f);            // Move the object back by 1
        glRotatef(rot * rotSpeed, 0.0f, 1.0f, 0.0f);  // Setup the rotation

        // We're telling OpenGL that we want to render triangles.
        glBegin(GL_TRIANGLES);

        //drawRaw();
        drawWinged();
        glEnd();

        glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

        rot += 0.1f;
    }
}

void Pyramid::drawWinged()
{
    for (Face face : faces)
    {
        for (Edge edge : face.edges)
        {
            for (Vertex vertex : edge.vertices)
            {
                if (vertex.color != NULL)
                {
                    glColor3f(vertex.color->red, vertex.color->green, vertex.color->blue);
                }
                else {
                    glColor3f(1.0f, 0.0f, 0.0f);
                }

                glVertex3f(vertex.point->x, vertex.point->y, vertex.point->z);
            };
        };
    };
}

/*
    Draw a pyramid without the winged-data structure
    @todo: Remove this in future
*/
void Pyramid::drawRaw()
{
    // Each of the pyramid's faces will have 3 vertices.
    // We'll start drawing at the top, then go down to the bottom left,
    // then to the right.

    // When we start our next triangle, we're going to be going back to
    // the top-middle. Imagine drawing a pyramid without ever lifting your
    // pen up.

    // New Triangle - Front
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // TODO: Utilizar este para renderizar a partir dos vertices
    //glVertex3fv();

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // New Triangle - Right
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // New Triangle - Back
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    // New Triangle - left
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // New Triangle - Bottom 1
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    // New Triangle - Bottom 2
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);      // Note: we're starting from the last point
                                          // of the previous triangle.

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
}
