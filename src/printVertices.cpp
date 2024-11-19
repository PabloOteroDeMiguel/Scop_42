#include "../include/Object.h"
#include "../include/Scop.h"
#include <iostream>

void printVertices(Object* obj) {
    glBegin(GL_POINTS);

    // for (int i = 0; i < obj->num_vertices; i++) {
    //     Vertex transformed_vertex = obj->vertex[i];
    //     scaleVertex(&transformed_vertex, obj->scale);
    //     rotateVertexY(&transformed_vertex, obj->angle_x);
    //     rotateVertexX(&transformed_vertex, obj->angle_y);
    //     glVertex3f(transformed_vertex.x, transformed_vertex.y, transformed_vertex.z);
    // }
    for (int i = 0; i < obj->num_vertices; i++) {
        Vertex transformed_vertex = obj->vertex[i];
        scaleVertex(&transformed_vertex, obj->scale);
        // Translate to center, rotate, then translate back
        transformed_vertex.x -= obj->center_x;
        transformed_vertex.y -= obj->center_y;
        transformed_vertex.z -= obj->center_z;
        rotateVertexY(&transformed_vertex, obj->angle_x);
        rotateVertexX(&transformed_vertex, obj->angle_y);
        transformed_vertex.x += obj->center_x;
        transformed_vertex.y += obj->center_y;
        transformed_vertex.z += obj->center_z;
        glVertex3f(transformed_vertex.x, transformed_vertex.y, transformed_vertex.z);
    }
    if (obj->move){
            obj->angle_x += 0.5f;
            if (obj->angle_x >= 360.0f) {
                obj->angle_x -= 360.0f;
            } else if (obj->angle_x < 0.0f) {
                obj->angle_x += 360.0f;
            }
    }
    glEnd();
}
