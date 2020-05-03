#include <GL/freeglut.h>
#include "OpenGLManager.h"

void OpenGLManager::initialize()
{
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

void OpenGLManager::window(int argc, char** argv, const char* title)
{
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowSize(640, 480);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow(title);          // Create window with the given title
}

void OpenGLManager::display(Shape3D *shape3d)
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


    while (true) {

        glMatrixMode(GL_MODELVIEW);

        // Now we need to clear both the color buffer AND the depth buffer when we
        // go to draw.
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        glLoadIdentity();                        // Load a blank matrix to work with

        gluLookAt(shape3d->xPos, shape3d->yPos, shape3d->zPos,                // This is essentially our camera
            0, 0, 0,
            0, 1, 0);

        // Our transformations for our pyramid
        glTranslatef(0.0f, 0.0f, -1.0f);            // Move the object back by 1
        glRotatef(shape3d->getRotationValue() * shape3d->getRotationSpeed(), 0.0f, 1.0f, 0.0f);  // Setup the rotation

        shape3d->draw();

        glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

        shape3d->incrementRotation();
    }
}

void OpenGLManager::reshape(GLsizei width, GLsizei height)
{
    // Compute aspect ratio of the new window
    if (height == 0) height = 1;                // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping volume to match the viewport
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();             // Reset
    // Enable perspective projection with fovy, aspect, zNear and zFar
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
