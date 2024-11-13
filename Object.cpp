#include <GLFW/glfw3.h>
#include <iostream>

void Object::startWin() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }

    GLFWwindow* win;
    win = glfwCreateWindow(1280, 720, "SCOP", NULL, NULL);
    if (!win) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    this->win = win;
}
