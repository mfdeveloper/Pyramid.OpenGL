/*
 * OGL01Shape3D.cpp: 3D Shapes
 */
#include <GL/freeglut.h>
#include <stdio.h>
#include "Pyramid.h"

/* Global variables */
char title[] = "3D Shapes";

Pyramid pyramid;

void initOpenGL() {

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

void display() {
    pyramid.draw(true);
}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
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

int main(int argc, char** argv) {
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowSize(640, 480);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow(title);          // Create window with the given title

    glutDisplayFunc(&display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event

    initOpenGL();

    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}