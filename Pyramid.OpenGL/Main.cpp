/*
 * Pyramid: 3D Shapes
 */
#include <GL/freeglut.h>
#include <map>
#include "OpenGLManager.h"
#include "Pyramid.h"

using namespace std;

/* Global variables */
char title[] = "3D Shapes";

OpenGLManager openGL;
Pyramid pyramid;

void createWinged() {

    // ------ Front => Face 1 ------
    map<string, Vertex*> verticesFront = {
        {"Front.A", new Vertex("Front.A", new Point(0.0f, 1.0f, 0.0f), new Color(1.0f, 0.0f, 0.0f)) },
        {"Front.B", new Vertex("Front.B", new Point(-1.0f, -1.0f, 1.0f), new Color(0.0f, 1.0f, 0.0f)) },
        {"Front.C", new Vertex("Front.C", new Point(1.0f, -1.0f, 1.0f), new Color(0.0f, 0.0f, 1.0f)) }
    };

    Edge* edgeFrontA = new Edge("Front.a");
    edgeFrontA->vertexOrigin = verticesFront["Front.A"];
    edgeFrontA->vertexDestiny = verticesFront["Front.B"];

    Edge* edgeFrontB = new Edge("Front.b");
    edgeFrontB->vertexOrigin = verticesFront["Front.A"];
    edgeFrontB->vertexDestiny = verticesFront["Front.C"];

    Edge* edgeFrontC = new Edge("Front.c");
    edgeFrontB->vertexOrigin = verticesFront["Front.C"];
    edgeFrontB->vertexDestiny = verticesFront["Front.B"];

    // Edges relationships
    edgeFrontA->edgeRightNext = edgeFrontB;
    edgeFrontA->edgeRightBack = edgeFrontC;

    edgeFrontB->edgeLeftNext = edgeFrontA;
    edgeFrontB->edgeLeftBack = edgeFrontC;

    edgeFrontC->edgeLeftNext = edgeFrontA;
    edgeFrontC->edgeRightNext = edgeFrontB;

    // Face relationships
    Face* faceFront1 = new Face("Front.1");

    edgeFrontA->faceRight = faceFront1;
    edgeFrontB->faceLeft = faceFront1;
    edgeFrontC->faceLeft = faceFront1;

    faceFront1->vertices = { {
        verticesFront["Front.A"],
        verticesFront["Front.B"],
        verticesFront["Front.C"]
    } };

    pyramid.faces.push_back(faceFront1);

    pyramid.edges.push_back(edgeFrontA);
    pyramid.edges.push_back(edgeFrontB);
    pyramid.edges.push_back(edgeFrontC);

    // ------ Right => Face 2 ------
    map<string, Vertex*> verticesRight = {
        {"Right.A", new Vertex("Right.A", new Point(0.0f, 1.0f, 0.0f), new Color(1.0f, 0.0f, 0.0f)) },
        {"Right.C", new Vertex("Right.C", new Point(1.0f, -1.0f, 1.0f), new Color(0.0f, 1.0f, 0.0f)) },
        {"Right.D", new Vertex("Right.D", new Point(1.0f, -1.0f, -1.0f), new Color(0.0f, 0.0f, 1.0f)) }
    };

    Edge* edgeRightB = new Edge("Right.b");
    edgeRightB->vertexOrigin = verticesRight["Right.A"];
    edgeRightB->vertexDestiny = verticesRight["Right.C"];

    Edge* edgeRightD = new Edge("Right.d");
    edgeRightD->vertexOrigin = verticesRight["Right.A"];
    edgeRightD->vertexDestiny = verticesRight["Right.D"];

    Edge* edgeRightE = new Edge("Right.e");
    edgeRightE->vertexOrigin = verticesRight["Right.D"];
    edgeRightE->vertexDestiny = verticesRight["Right.C"];

    // Edges relationships
    edgeRightB->edgeRightNext = edgeRightE;
    edgeRightB->edgeRightBack = edgeRightD;

    edgeRightD->edgeLeftNext = edgeRightB;
    edgeRightD->edgeLeftBack = edgeRightE;

    edgeRightE->edgeLeftNext = edgeRightB;
    edgeRightE->edgeRightNext = edgeRightD;

    // Face relationships
    Face* faceRight2 = new Face("Right.2");

    edgeRightB->faceRight = faceRight2;
    edgeRightB->faceLeft = faceFront1;
    edgeRightD->faceLeft = faceRight2;
    edgeRightE->faceLeft = faceRight2;

    faceRight2->vertices = { {
        verticesRight["Right.A"],
        verticesRight["Right.C"],
        verticesRight["Right.D"]
    } };

    pyramid.faces.push_back(faceRight2);

    pyramid.edges.push_back(edgeRightB);
    pyramid.edges.push_back(edgeRightD);
    pyramid.edges.push_back(edgeRightE);

    // ------ Back => Face 3 ------
    map<string, Vertex*> verticesBack = {
        {"Back.A", new Vertex("Back.A", new Point(0.0f, 1.0f, 0.0f), new Color(1.0f, 0.0f, 0.0f)) },
        {"Back.D", new Vertex("Back.D", new Point(1.0f, -1.0f, -1.0f), new Color(0.0f, 1.0f, 0.0f)) },
        {"Back.E", new Vertex("Back.E", new Point(-1.0f, -1.0f, -1.0f), new Color(0.0f, 0.0f, 1.0f)) }
    };

    Edge* edgeBackD = new Edge("Back.d");
    edgeBackD->vertexOrigin = verticesBack["Back.A"];
    edgeBackD->vertexDestiny = verticesBack["Back.D"];

    Edge* edgeBackF = new Edge("Back.f");
    edgeBackF->vertexOrigin = verticesBack["Back.A"];
    edgeBackF->vertexDestiny = verticesBack["Back.E"];

    Edge* edgeBackG = new Edge("Back.g");
    edgeBackG->vertexOrigin = verticesBack["Back.D"];
    edgeBackG->vertexDestiny = verticesBack["Back.E"];

    // Edges relationships
    edgeBackD->edgeRightNext = edgeBackF;
    edgeBackD->edgeRightBack = edgeBackG;
    edgeBackD->edgeLeftNext = edgeRightB;
    edgeBackD->edgeLeftBack = edgeRightE;

    edgeBackF->edgeLeftNext = edgeBackD;
    edgeBackF->edgeLeftBack = edgeBackG;

    edgeBackG->edgeLeftNext = edgeBackD;
    edgeBackG->edgeRightNext = edgeBackF;

    // Face relationships
    Face* faceBack3 = new Face("Back.3");

    edgeBackD->faceRight = faceBack3;
    edgeBackD->faceLeft = faceRight2;

    edgeBackF->faceLeft = faceBack3;
    edgeBackG->faceLeft = faceBack3;

    faceBack3->vertices = { {
        verticesRight["Back.A"],
        verticesRight["Back.D"],
        verticesRight["Back.E"]
    } };

    pyramid.faces.push_back(faceBack3);

    pyramid.edges.push_back(edgeBackD);
    pyramid.edges.push_back(edgeBackF);
    pyramid.edges.push_back(edgeBackG);

    // ------ Left => Face 4 ------
    map<string, Vertex*> verticesLeft = {
        {"Left.A", new Vertex("Left.A", new Point(0.0f, 1.0f, 0.0f), new Color(1.0f, 0.0f, 0.0f)) },
        {"Left.F", new Vertex("Left.F", new Point(-1.0f, -1.0f, -1.0f), new Color(0.0f, 1.0f, 0.0f)) },
        {"Left.B", new Vertex("Left.B", new Point(-1.0f, -1.0f, 1.0f), new Color(0.0f, 0.0f, 1.0f)) }
    };

    Edge* edgeLeftH = new Edge("Left.h");
    edgeLeftH->vertexOrigin = verticesLeft["Left.A"];
    edgeLeftH->vertexDestiny = verticesLeft["Left.F"];

    Edge* edgeLeftA = new Edge("Left.a");
    edgeLeftA->vertexOrigin = verticesLeft["Left.A"];
    edgeLeftA->vertexDestiny = verticesLeft["Left.B"];

    Edge* edgeLeftI = new Edge("Left.i");
    edgeLeftI->vertexOrigin = verticesLeft["Left.B"];
    edgeLeftI->vertexDestiny = verticesLeft["Left.F"];

    // Edges relationships
    edgeLeftH->edgeRightNext = edgeFrontA;
    edgeLeftH->edgeRightBack = edgeLeftI;
    edgeLeftH->edgeLeftNext = edgeBackF;
    edgeLeftH->edgeLeftBack = edgeBackG;

    edgeLeftA->edgeRightNext = edgeFrontB;
    edgeLeftA->edgeRightBack = edgeFrontC;
    edgeLeftA->edgeLeftNext = edgeLeftH;
    edgeLeftA->edgeLeftBack = edgeLeftI;

    edgeFrontA->edgeLeftNext = edgeLeftH;
    edgeFrontA->edgeLeftBack = edgeLeftI;

    edgeLeftI->edgeRightNext = edgeFrontA;
    edgeLeftI->edgeLeftNext = edgeLeftH;

    // Face relationships
    Face* faceLeft4 = new Face("Left.4");

    edgeLeftH->faceRight = faceLeft4;
    edgeLeftH->faceLeft = faceBack3;

    edgeLeftA->faceRight = faceFront1;
    edgeLeftA->faceLeft = faceLeft4;

    edgeLeftI->faceLeft = faceLeft4;

    faceLeft4->vertices = { {
        verticesRight["Left.A"],
        verticesRight["Left.F"],
        verticesRight["Left.B"]
    } };

    pyramid.faces.push_back(faceLeft4);

    pyramid.edges.push_back(edgeLeftH);
    pyramid.edges.push_back(edgeLeftA);
    pyramid.edges.push_back(edgeLeftI);

    // ------ Bottom 1 => Face 5 ------
    map<string, Vertex*> verticesBottom1 = {
        {"Bottom1.F", new Vertex("Bottom1.F", new Point(-1.0f, -1.0f, 1.0f), new Color(1.0f, 0.0f, 0.0f)) },
        {"Bottom1.G", new Vertex("Bottom1.G", new Point(1.0f, -1.0f, 1.0f), new Color(0.0f, 1.0f, 0.0f)) },
        {"Bottom1.E", new Vertex("Bottom1.E", new Point(-1.0f, -1.0f, -1.0f), new Color(0.0f, 0.0f, 1.0f)) }
    };

    Edge* edgeBottom1J = new Edge("Bottom1.j");
    edgeBottom1J->vertexOrigin = verticesBottom1["Bottom1.F"];
    edgeBottom1J->vertexDestiny = verticesBottom1["Bottom1.G"];

    Edge* edgeBottom1I = new Edge("Bottom1.i");
    edgeBottom1I->vertexOrigin = verticesBottom1["Bottom1.F"];
    edgeBottom1I->vertexDestiny = verticesBottom1["Bottom1.E"];

    Edge* edgeBottom1L = new Edge("Bottom1.l");
    edgeBottom1L->vertexOrigin = verticesBottom1["Bottom1.E"];
    edgeBottom1L->vertexDestiny = verticesBottom1["Bottom1.G"];

    // Edges relationships
    edgeBottom1J->edgeRightNext = edgeBottom1L;

    edgeBottom1I->edgeRightNext = edgeBottom1L;
    edgeBottom1I->edgeRightBack = edgeBottom1J;

    edgeBottom1L->edgeLeftNext = edgeBottom1I;

    // Face relationships
    Face* faceBottom5 = new Face("Bottom1.5");

    edgeBottom1J->faceRight = faceBottom5;

    edgeBottom1I->faceRight = faceBottom5;
    edgeBottom1I->faceLeft = faceLeft4;

    edgeLeftI->faceRight = faceBottom5;

    edgeBottom1L->faceLeft = faceBottom5;

    faceBottom5->vertices = { {
        verticesBottom1["Bottom1.F"],
        verticesBottom1["Bottom1.G"],
        verticesBottom1["Bottom1.E"]
    } };

    pyramid.faces.push_back(faceBottom5);

    pyramid.edges.push_back(edgeBottom1J);
    pyramid.edges.push_back(edgeBottom1I);
    pyramid.edges.push_back(edgeBottom1L);

    // ------ Bottom 2 => Face 6 ------
    map<string, Vertex*> verticesBottom2 = {
        {"Bottom2.G", new Vertex("Bottom2.G", new Point(-1.0f, -1.0f, -1.0f), new Color(1.0f, 0.0f, 0.0f)) },
        {"Bottom2.E", new Vertex("Bottom2.E", new Point(1.0f, -1.0f, -1.0f), new Color(0.0f, 1.0f, 0.0f)) },
        {"Bottom2.H", new Vertex("Bottom2.H", new Point(1.0f, -1.0f, 1.0f), new Color(0.0f, 0.0f, 1.0f)) }
    };

    Edge* edgeBottom2L = new Edge("Bottom2.l");
    edgeBottom2L->vertexOrigin = verticesBottom2["Bottom2.G"];
    edgeBottom2L->vertexDestiny = verticesBottom2["Bottom2.E"];

    Edge* edgeBottom2M = new Edge("Bottom2.m");
    edgeBottom2M->vertexOrigin = verticesBottom2["Bottom2.G"];
    edgeBottom2M->vertexDestiny = verticesBottom2["Bottom2.H"];

    Edge* edgeBottom2N = new Edge("Bottom2.n");
    edgeBottom2N->vertexOrigin = verticesBottom2["Bottom2.E"];
    edgeBottom2N->vertexDestiny = verticesBottom2["Bottom2.H"];

    // Edges relationships
    edgeBottom2L->edgeLeftNext = edgeBottom2M;
    edgeBottom2L->edgeLeftBack = edgeBottom2N;

    edgeBottom2M->edgeRightNext = edgeBottom2L;
    edgeBottom2M->edgeRightBack = edgeBottom2N;

    edgeBottom2N->edgeRightNext = edgeBottom2L;
    edgeBottom2N->edgeLeftNext = edgeBottom2M;

    // Face relationships
    Face* faceBottom6 = new Face("Bottom2.6");

    edgeBottom2L->faceRight = faceBottom5;
    edgeBottom2L->faceLeft = faceBottom6;

    edgeBottom2M->faceRight = faceBottom6;
    edgeBottom2M->faceLeft = faceBack3;

    edgeBottom2N->faceLeft = faceBottom6;

    faceBottom6->vertices = { {
        verticesBottom1["Bottom2.G"],
        verticesBottom1["Bottom2.E"],
        verticesBottom1["Bottom2.H"]
    } };

    pyramid.faces.push_back(faceBottom6);

    pyramid.edges.push_back(edgeBottom2L);
    pyramid.edges.push_back(edgeBottom2M);
    pyramid.edges.push_back(edgeBottom2N);
}

void display() {

    openGL.display(&pyramid);

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
