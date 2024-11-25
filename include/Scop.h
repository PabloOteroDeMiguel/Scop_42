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

//inputKey
void key_callback(GLFWwindow* window, int key, int, int action, int);

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
void    calculateGrayscaleColor(float &r, float &g, float &b, int index, int num_faces);

//instructions
void    instructions();

//utils
std::vector<std::string> splitString(const std::string &s, char delimiter);
void    frameSize(GLFWwindow* window, int width, int height);

#endif