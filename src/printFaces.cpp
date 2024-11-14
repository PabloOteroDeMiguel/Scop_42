#include "../include/Object.h"
#include "../include/Scop.h"
#include <iostream>

void printFaces(Object* obj) {
    int vertex_index[4];
    GLfloat f[4][3];

    if (obj->texture) {
        glBindTexture(GL_TEXTURE_2D, obj->texture);
    }

    glBegin(GL_TRIANGLES);

    for (int f_cont = 0; f_cont < obj->num_faces; f_cont++){
        
        vertex_index[0] = obj->faces[f_cont].x - 1;
        vertex_index[1] = obj->faces[f_cont].y - 1;
        vertex_index[2] = obj->faces[f_cont].z - 1;
        vertex_index[3] = obj->faces[f_cont].t - 1;

        for (int i = 0; i < 4; i++) {
            if(!vertex_index[i]){
                continue;
            }
            Vertex transformed_vertex = obj->vertex[vertex_index[i]];
            scaleVertex(&transformed_vertex, obj->scale);
            rotateVertexY(&transformed_vertex, obj->angle_x);
            rotateVertexX(&transformed_vertex, obj->angle_y);

            f[i][0] = transformed_vertex.x;
            f[i][1] = transformed_vertex.y;
            f[i][2] = transformed_vertex.z;
        }
        float r, g, b;
        generateColor(&r, &g, &b, obj->faces[f_cont].face_color, obj->color);
        glColor3f(r, g, b);

        if (vertex_index[3] && vertex_index[3] > 0){
            if (obj->texture) {
                if (obj->num_texcoords > 0) {
                    glTexCoord2f(obj->textcoords[vertex_index[0]].u, obj->textcoords[vertex_index[0]].v);
                    glTexCoord2f(obj->textcoords[vertex_index[2]].u, obj->textcoords[vertex_index[2]].v);
                    glTexCoord2f(obj->textcoords[vertex_index[3]].u, obj->textcoords[vertex_index[3]].v);
                }
                else if (obj->mode == 4) { 
                    glTexCoord2f(obj->vertex[vertex_index[0]].x, obj->vertex[vertex_index[0]].y);
                    glTexCoord2f(obj->vertex[vertex_index[2]].x, obj->vertex[vertex_index[2]].y);
                    glTexCoord2f(obj->vertex[vertex_index[3]].x, obj->vertex[vertex_index[3]].y);
                } 
                else {
                    // Generate default texture coordinates
                    glTexCoord2f(0.0f, 0.0f);
                    glTexCoord2f(1.0f, 0.0f);
                    glTexCoord2f(1.0f, 1.0f);
                }
            }
            glVertex3f(f[0][0], f[0][1], f[0][2]);
            glVertex3f(f[2][0], f[2][1], f[2][2]);
            glVertex3f(f[3][0], f[3][1], f[3][2]);
        }

        for (int i = 0; i < 3; i++) {
            if (obj->texture) {
                if (obj->num_texcoords > 0) {
                    glTexCoord2f(obj->textcoords[vertex_index[i]].u, obj->textcoords[vertex_index[i]].v);
                }
                else if (obj->mode == 4) {
                     glTexCoord2f(obj->vertex[vertex_index[i]].x, obj->vertex[vertex_index[i]].y);
                }
                else {
                    // Generate default texture coordinates
                    glTexCoord2f((i == 0) ? 0.0f : 1.0f, (i == 2) ? 1.0f : 0.0f);
                }
            }
            glVertex3f(f[i][0], f[i][1], f[i][2]); 
        }
    }
    glEnd();
}
