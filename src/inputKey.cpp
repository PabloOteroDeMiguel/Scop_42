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
            obj->mode = 1;
            obj->color = (obj->color == 1) ? 0 : 1;
            obj->textureKeyPressed = false;
        }
        else if (key == GLFW_KEY_2) {
            obj->mode = 2;
            obj->color = (obj->color == 2) ? 0 : 2;
            obj->textureKeyPressed = false;
        }
        else if (key == GLFW_KEY_3) {
            if (obj->textureKeyPressed && obj->mode == 3) {
                obj->mode = 0;
                obj->color = 0;
                obj->textureKeyPressed = false;
            } else {
                obj->color = 0;
                obj->mode = 3;
                obj->textureKeyPressed = true;
            }
        }
        else if (key == GLFW_KEY_4) {
            if (obj->textureKeyPressed && obj->mode == 4) {
                obj->mode = 0;
                obj->color = 0;
                obj->textureKeyPressed = false;
            } else {
                obj->color = 0;
                obj->mode = 4;
                obj->textureKeyPressed = true;
            }
        }
        else if (key == GLFW_KEY_ESCAPE) {
            obj->endScop();
        }
    }
}
