// Object.cpp
#include "../include/Object.h" 
#include "../include/Scop.h"
#include <string.h>
#include <vector>
#include <sstream>
#include <cstdlib>

// Constructor

Object::Object() : 
        num_vertices(0), 
        num_faces(0), 
        num_texcoords(0), 
        color(0),
        mode(0),
        scale(1.0f), 
        angle_x(0.0f), 
        angle_y(0.0f), 
        center_x(0.0f),
        center_y(0.0f),
        center_z(0.0f),
        tKeyPressed(false), 
        textureKeyPressed(false),
        move(false),
        texture(0), 
        vertex(NULL), 
        faces(NULL),
        textcoords(NULL) {}

Object::Object(char* filename) : 
        num_vertices(0), 
        num_faces(0), 
        num_texcoords(0), 
        color(0),
        mode(0),
        scale(1.0f), 
        angle_x(0.0f), 
        angle_y(0.0f),
        center_x(0.0f),
        center_y(0.0f),
        center_z(0.0f), 
        tKeyPressed(false), 
        textureKeyPressed(false),
        move(false),
        texture(0),
        vertex(NULL), 
        faces(NULL), 
        textcoords(NULL) {

    this->filename = filename;
}

// Destructor
Object::~Object() {
    // Cleaning
    delete[] this->vertex;
    delete[] this->faces;
    delete[] this->textcoords;
}

// Methods

void Object::countVerticesAndFaces() {
    std::ifstream file(this->filename);
    std::string line;
    while (std::getline(file, line)) {
        if (line[0] == 'v' && line[1] == ' ') {
            this->num_vertices++;
        }
        else if (line[0] == 'f' && line[1] == ' ') {
            this->num_faces++;
        }
        else if (line[0] == 'v' && line[1] == 't' && line[2] == ' ') {
            this->num_texcoords++;
        }
    }
    file.close();

    // Allocate memory for vertices, faces and textures after counting
    this->vertex = new Vertex[this->num_vertices];
    this->faces = new Face[this->num_faces];
    this->textcoords = new Textcoord[this->num_texcoords];

    std::cout << "Vertices:\t" << this->num_vertices << std::endl;
    std::cout << "Faces:\t\t" << this->num_faces << std::endl;
    std::cout << "Texture coord:\t" << this->num_texcoords << std::endl;
}



void Object::saveVertices() {
    int v_cont = 0;
    float f[3];
    std::ifstream file(this->filename);
    std::string line;
    Vertex v;

    while (std::getline(file, line)) {
        if (line[0] == 'v' && line[1] == ' ') {
            std::vector<std::string> split = splitString(line, ' ');
            f[0] = strtof(split[1].c_str(), NULL);
            v.x = f[0];
            f[1] = strtof(split[2].c_str(), NULL);
            v.y = f[1];
            f[2] = strtof(split[3].c_str(), NULL);
            v.z = f[2];
            this->vertex[v_cont] = v;
            v_cont++;
        }
    }
    file.close();
}

void Object::saveFaces() {
    int f_cont = 0;
    int f_color = 0;
    float f[4];
    std::ifstream file(this->filename);
    std::string line;
    Face fa;

    while (std::getline(file, line)) {
        if (line[0] == 'f' && line[1] == ' ') {
            std::vector<std::string> split = splitString(line, ' ');
            f[0] = strtof(split[1].c_str(), NULL);
            fa.x = f[0];
            f[1] = strtof(split[2].c_str(), NULL);
            fa.y = f[1];
            f[2] = strtof(split[3].c_str(), NULL);
            fa.z = f[2];
            if (split.size() > 4 && !split[4].empty()) {
                f[3] = strtof(split[4].c_str(), NULL);
                fa.t = f[3];
            } else {
                fa.t = 0;  // Default value
            }
            fa.face_color = f_color;
            f_color++;
            if (f_color > 5) {
                f_color = 0;
            }
            this->faces[f_cont] = fa;
            f_cont++;
        }
    }
    file.close();
}

void Object::saveTexture() {
    std::ifstream file(this->filename);
    std::string line;
    int cont = 0;

    while (std::getline(file, line)) {
        if (line[0] == 'v' && line[1] == 't'  && line[2] == ' '){
            Textcoord texcoord;
            std::vector<std::string> split = splitString(line, ' ');
            if (split.size() < 3) {
                std::cerr << "Invalid texture coordinate line: " << line << std::endl;
                continue;
            }
            texcoord.u = strtof(split[1].c_str(), NULL);
            texcoord.v = strtof(split[2].c_str(), NULL);
            this->textcoords[cont++] = texcoord;
       }
    }
    file.close();
}

void Object::centerObject() {
    float sum_x = 0, sum_y = 0, sum_z = 0;

    // Calculate center of the object
    for (int i = 0; i < this->num_vertices; i++) {
        sum_x += this->vertex[i].x;
        sum_y += this->vertex[i].y;
        sum_z += this->vertex[i].z;
    }

    float centroid_x = sum_x / this->num_vertices;
    float centroid_y = sum_y / this->num_vertices;
    float centroid_z = sum_z / this->num_vertices;

    // Adjust new coordinates
    for (int i = 0; i < this->num_vertices; i++) {
        this->vertex[i].x -= centroid_x;
        this->vertex[i].y -= centroid_y;
        this->vertex[i].z -= centroid_z;
    }
}

void Object::setMode() {
    switch (this->mode) {
        case 0:
            this->color = 0;
            this->textureKeyPressed = false;
            break;
        case 1:
            this->color = 1;
            this->textureKeyPressed = false;
            break;
        case 2:
            this->color = 2;
            this->textureKeyPressed = false;
            break;
        case 3:
            this->color = 0;
            this->textureKeyPressed = true;
            break;
        case 4:
            this->color = 0;
            this->textureKeyPressed = true;
            break;
        case 5:
            this->color = 0;
            this->textureKeyPressed = false;
            break;
    }
}

void Object::moveX(float delta) {
    for (int i = 0; i < this->num_vertices; i++) {
        this->vertex[i].x += delta;     
    }
    this->center_x += delta;
    //this->centerObject();
}

void Object::moveY(float delta) {
    for (int i = 0; i < this->num_vertices; i++) {
        this->vertex[i].y += delta;
        
    }
    this->center_y += delta;
    //this->centerObject();
}

void Object::startWin() {
    GLFWwindow* win;
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE); // Make window resizable
    win = glfwCreateWindow(1080, 720, "SCOP", NULL, NULL);
    if (!win) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    this->win = win;
    glfwSetWindowUserPointer(win, this);
    glfwSetKeyCallback(win, key_callback);
    glfwSetFramebufferSizeCallback(win, frameSize); // Set resize callback
}

void Object::scopLoop() {
    glfwMakeContextCurrent(this->win);
    GLenum err = glewInit();
    if(err != GLEW_OK)
    {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        exit(EXIT_FAILURE);
    }

    const GLubyte *renderer = glGetString(GL_RENDERER);
    const GLubyte *version = glGetString(GL_VERSION);
    std::cout << "Renderer:\t" << renderer << std::endl;
    std::cout << "OpenGL VS:\t" << version << std::endl;
    const GLubyte *glewVersion = glewGetString(GLEW_VERSION);
    std::cout << "GLEW version:\t" << glewVersion << std::endl;
    std::cout << "--->SCOP<---" << std::endl;

    std::string path = this->filename;
    this->color = 0;
    path = path.substr(0, path.size() - 4) + ".bmp";
    this->texture = loadTexture(path);

    // Ensure texture is loaded and bound correctly
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    instructions();

    while(!glfwWindowShouldClose(this->win)){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glTexCoordPointer(2, GL_FLOAT, 0, this->textcoords);

        glPushMatrix();
        glScalef(this->scale, this->scale, this->scale); // Apply scaling
        printVertices(this);
        printFaces(this);
        glPopMatrix();

        glDisableClientState(GL_TEXTURE_COORD_ARRAY);

        glfwSwapBuffers(this->win);
        glfwPollEvents();
    }
    endScop();
}

void Object::endScop() {
    std::cout << "Goodbye" << std::endl;
    glfwDestroyWindow(this->win);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}


