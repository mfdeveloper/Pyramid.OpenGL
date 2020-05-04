// FileOff.OpenGL.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <GL/freeglut.h>
#include <map>
#include "Shape3D.cpp"
#include "Color.cpp"
#include "Point.cpp"
#include "Vertex.cpp"
#include "Face.cpp"
#include "OpenGLManager.cpp"
#include "FileOff.cpp"
#include "FileOffRender.cpp"

using namespace std;

/* Global variables */
char title[] = "3D Shapes";

OpenGLManager openGL;
FileOffRender* fileRender = new FileOffRender();

void createWinged() {

    FileOff* fileOff = new FileOff();

    string fullPath = fileOff->getCurrentDir() + "\\Pyramid.OpenGL\\FileOff.OpenGL\\cube.off";
    fileRender->fileOff = fileOff->load(fullPath);
}

void display() {

    openGL.display(fileRender);

}

void reshape(GLsizei width, GLsizei height) {
    openGL.reshape(width, height);
}

int main(int argc, char** argv) {

    // ------------- Vertices, Edges and Faces ------------
    createWinged();

    openGL.window(argc, argv, title);

    //TODO: Move these opengl functions to "OpenGLManager" class
    glutDisplayFunc(&display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event

    openGL.initialize();

    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
