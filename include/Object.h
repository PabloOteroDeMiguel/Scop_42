// Object.h
#ifndef OBJECT_H 
#define OBJECT_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Vertex.h"
#include "Vertex.h"
#include "Face.h"
#include "Textcoord.h"

class Object {
public:

    GLFWwindow* win;

    char*       filename;

    int			num_vertices;
	int			num_faces;
	int			num_texcoords;
	int			color;
    int         mode;

    float		(*vertices)[3];
	float		scale;
    float       angle_x;
    float       angle_y;

    bool        tKeyPressed;
    bool        textureKeyPressed;
    GLuint      texture;
    Vertex      *vertex;
    Face        *faces;
    Textcoord   *textcoords;

    // Constructor
    Object();
    Object(char* filename);

    // Destructor
    ~Object();

    // Methods
    bool validateFile();

    void countVerticesAndFaces();
    void saveVertices();
    void saveFaces();
    void saveTexture();
    void centerObject();
    void setMode();
    void startWin();
    void scopLoop();
    //void loadVertices(const char* filename);
    //void loadFaces(const char* filename);
    
    //void render();
    //void handleInput();

private:

};

#endif // OBJECT_H