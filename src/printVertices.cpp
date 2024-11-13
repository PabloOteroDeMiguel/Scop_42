#include "../include/Object.h"
#include "../include/Scop.h"
#include <iostream>

void printVertices(Object* obj) {
    glBegin(GL_POINTS);

    for (int i = 0; i < obj->num_vertices; i++) {
        Vertex transformed_vertex = obj->vertex[i];
        scaleVertex(&transformed_vertex, obj->scale);
        rotateVertexY(&transformed_vertex, obj->angle_x);
        rotateVertexX(&transformed_vertex, obj->angle_y);
        glVertex3f(transformed_vertex.x, transformed_vertex.y, transformed_vertex.z);
    }

    glEnd();
}
