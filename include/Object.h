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
    float       center_x;
    float       center_y;
    float       center_z;


    bool        tKeyPressed;
    bool        textureKeyPressed;
    bool        move;
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
    void moveX(float delta);
    void moveY(float delta);
    void startWin();
    void scopLoop();
    void endScop();
    //void loadVertices(const char* filename);
    //void loadFaces(const char* filename);
    
    //void render();
    //void handleInput();

private:

};

#endif // OBJECT_H