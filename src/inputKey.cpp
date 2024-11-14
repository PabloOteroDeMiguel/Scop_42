#include "../include/Object.h"
#include "../include/Scop.h"

void key_callback(GLFWwindow* window, int key, int /*scancode*/, int action, int /*mods*/) {
    Object* obj = static_cast<Object*>(glfwGetWindowUserPointer(window));
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        if (key == GLFW_KEY_D) {
            obj->angle_x += 5.0f;
        }
        else if (key == GLFW_KEY_A) {
            obj->angle_x -= 5.0f;
        }
        else if (key == GLFW_KEY_E) {
            obj->scale += 0.1f;
        }
        else if (key == GLFW_KEY_Q) {
            obj->scale -= 0.1f;
            if (obj->scale < 0) {
                obj->scale = 0;
            }
        }
        else if (key == GLFW_KEY_W) {
            obj->angle_y += 5.0f;
        }
        else if (key == GLFW_KEY_S) {
            obj->angle_y -= 5.0f;
        }
        else if (key == GLFW_KEY_T) {
            obj->mode++;
            if (obj->mode > 4) { obj->mode = 0; }
            obj->setMode();  
        }
        else if (key == GLFW_KEY_1) {
            obj->texture = 0;
            obj->color = (obj->color == 1) ? 0 : 1;
            obj->textureKeyPressed = false;
        }
        else if (key == GLFW_KEY_2) {
            obj->texture = 0;
            obj->color = (obj->color == 2) ? 0 : 2;
            obj->textureKeyPressed = false;
        }
        else if (key == GLFW_KEY_3) {
            if (obj->textureKeyPressed) {
                obj->texture = 0; // Remove texture
                obj->color = 0;
                obj->textureKeyPressed = false;
            } else {
                std::string path = obj->filename;
                obj->color = 0;
                path = path.substr(0, path.size() - 4) + ".bmp";
                obj->texture = loadTexture(path);
                obj->textureKeyPressed = true;
            }
        }
    }
}
