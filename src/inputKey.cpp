#include "../include/Object.h"
#include "../include/Scop.h"

void input_key(Object* obj) {
    if (glfwGetKey(obj->win, GLFW_KEY_D) == GLFW_PRESS) {
        obj->angle_x += 5.0f;
    }
    else if (glfwGetKey(obj->win, GLFW_KEY_A) == GLFW_PRESS) {
        obj->angle_x -= 5.0f;
    }
    else if (glfwGetKey(obj->win, GLFW_KEY_E) == GLFW_PRESS) {
        obj->scale += 0.1f;
    }
    else if (glfwGetKey(obj->win, GLFW_KEY_Q) == GLFW_PRESS) {
        obj->scale -= 0.1f;
        if (obj->scale < 0) { //Para que no se invierta
            obj->scale = 0;
        }
    }
    else if (glfwGetKey(obj->win, GLFW_KEY_W) == GLFW_PRESS) {
        obj->angle_y += 5.0f; // Rotar hacia arriba
    }
    else if (glfwGetKey(obj->win, GLFW_KEY_S) == GLFW_PRESS) {
        obj->angle_y -= 5.0f; // Rotar hacia abajo
    }
    else if (glfwGetKey(obj->win, GLFW_KEY_T) == GLFW_PRESS) {
        obj->color += 1;

        if (obj->color >2) {
            obj->color = 0;
        }
        obj->textureKeyPressed = false;
    }
    else if (glfwGetKey(obj->win, GLFW_KEY_1) == GLFW_PRESS) {
        if (obj->color == 1) {
            obj->color = 0;
        }
        else {
            obj->color = 1;
        }
        obj->textureKeyPressed = false;
    }
    else if (glfwGetKey(obj->win, GLFW_KEY_2) == GLFW_PRESS) {
        if (obj->color == 2) {
            obj->color = 0;
        }
        else {
            obj->color = 2;
        }
        obj->textureKeyPressed = false;
    }
    else if (glfwGetKey(obj->win, GLFW_KEY_3) == GLFW_PRESS) {
        if (!obj->textureKeyPressed) {
            std::string path = obj->filename;
            path = path.substr(0, path.size() - 4);
            path += ".bmp";
            obj->texture = loadTexture(path);
            obj->textureKeyPressed = true; // Marcar la tecla como presionada
        }
    }
}
