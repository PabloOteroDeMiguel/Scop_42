#ifndef SCOP_H
#define SCOP_H


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Object.h"
#include "ValidateFile.h"
#include "checkGLError.h"

//printObject
void    printVertices(Object *obj);
void    printFaces(Object *obj);

//InputKey
void    input_key(Object* obj);

//matrixAndVertex
void    multiplyMatrixVector(float *v, float matrix[4][4]);
void    scaleVertex(Vertex *v, float scale);
void    rotateVertexY(Vertex *v, float angle);
void    rotateVertexX(Vertex *v, float angle);

//textureAndColor
void    generateRandomColor(float *r, float *g, float *b);
void    generateBasicColor(float *r, float *g, float *b, int color);
void    generateColor(float *r, float *g, float *b, int color, int type);
GLuint  loadTexture(std::string filepath);

#endif