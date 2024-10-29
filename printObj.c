/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printObj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:51:53 by potero-d          #+#    #+#             */
/*   Updated: 2024/03/20 11:34:16 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

// void printVertices(t_object *obj) {

//     glBegin(GL_POINTS);

//     for (int v_cont = 0; v_cont < obj->num_vertices; v_cont++){
//         glVertex3f(obj->s_vertices[v_cont]->x, obj->s_vertices[v_cont]->y, obj->s_vertices[v_cont]->z);
//     }

//     glEnd();
// }
void printVertices(t_object *obj) {
    glBegin(GL_POINTS);

    for (int v_cont = 0; v_cont < obj->num_vertices; v_cont++) {
        t_vertex transformed_vertex = *(obj->s_vertices[v_cont]);
        scaleVertex(&transformed_vertex, obj->scale);
        rotateVertexY(&transformed_vertex, obj->angle_x);
        rotateVertexX(&transformed_vertex, obj->angle_y);
        glVertex3f(transformed_vertex.x, transformed_vertex.y, transformed_vertex.z);
    }

    glEnd();
}

void printFaces(t_object *obj) {

    int vertex_index[4];
    GLfloat f[4][3];

    if (obj->texture) {
        glBindTexture(GL_TEXTURE_2D, obj->texture);
    }

    glBegin(GL_TRIANGLES);

    for (int f_cont = 0; f_cont < obj->num_faces; f_cont++){
        
            vertex_index[0] = obj->s_faces[f_cont]->x - 1;
            vertex_index[1] = obj->s_faces[f_cont]->y - 1;
            vertex_index[2] = obj->s_faces[f_cont]->z - 1;
            vertex_index[3] = obj->s_faces[f_cont]->t - 1;
            for (int i = 0; i < 3; i++) {
                if(!vertex_index[i]){
                    continue;
                }
                t_vertex transformed_vertex = *(obj->s_vertices[vertex_index[i]]);
                scaleVertex(&transformed_vertex, obj->scale);
                rotateVertexY(&transformed_vertex, obj->angle_x);
                rotateVertexX(&transformed_vertex, obj->angle_y);

                f[i][0] = transformed_vertex.x;
                f[i][1] = transformed_vertex.y;
                f[i][2] = transformed_vertex.z;
            }
            if (vertex_index[3] && vertex_index[3] > 0){
                t_vertex transformed_vertex = *(obj->s_vertices[vertex_index[3]]);
                scaleVertex(&transformed_vertex, obj->scale);
                rotateVertexY(&transformed_vertex, obj->angle_x);
                rotateVertexX(&transformed_vertex, obj->angle_y);

                f[3][0] = transformed_vertex.x;
                f[3][1] = transformed_vertex.y;
                f[3][2] = transformed_vertex.z;
                float r, g, b;
                generateColor(&r, &g, &b, obj->s_faces[f_cont]->face_color, obj->color);
                glColor3f(r, g, b);
                if (obj->texture && obj->num_texcoords > 0) {
                    glTexCoord2f(obj->s_texcoords[vertex_index[0]].u, obj->s_texcoords[vertex_index[0]].v);
                    glTexCoord2f(obj->s_texcoords[vertex_index[2]].u, obj->s_texcoords[vertex_index[2]].v);
                    glTexCoord2f(obj->s_texcoords[vertex_index[3]].u, obj->s_texcoords[vertex_index[3]].v);
                }
                glVertex3f(f[0][0], f[0][1], f[0][2]);
                glVertex3f(f[2][0], f[2][1], f[2][2]);
                glVertex3f(f[3][0], f[3][1], f[3][2]);
            }
            for (int i = 0; i < 3; i++) {
                float r, g, b;
                generateColor(&r, &g, &b, obj->s_faces[f_cont]->face_color, obj->color);
                glColor3f(r, g, b);
                if (obj->texture && obj->num_texcoords > 0) {
                    glTexCoord2f(obj->s_texcoords[vertex_index[i]].u, obj->s_texcoords[vertex_index[i]].v);
                }
                glVertex3f(f[i][0], f[i][1], f[i][2]);
            }
    }
    glEnd();
}