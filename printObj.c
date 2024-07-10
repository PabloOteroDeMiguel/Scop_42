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
        rotateVertexY(&transformed_vertex, obj->angle);

        glVertex3f(transformed_vertex.x, transformed_vertex.y, transformed_vertex.z);
    }

    glEnd();
}

void printFaces(t_object *obj) {

    int vertex_index[4];
    GLfloat f[4][3];

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
            rotateVertexY(&transformed_vertex, obj->angle);

            f[i][0] = transformed_vertex.x;
            f[i][1] = transformed_vertex.y;
            f[i][2] = transformed_vertex.z;
                // f[i][0] = obj->s_vertices[vertex_index[i]]->x;          
                // f[i][1] = obj->s_vertices[vertex_index[i]]->y;
                // f[i][2] = obj->s_vertices[vertex_index[i]]->z;  
            }
            if (vertex_index[3] && vertex_index[3] > 0){
                t_vertex transformed_vertex = *(obj->s_vertices[vertex_index[3]]);
                scaleVertex(&transformed_vertex, obj->scale);
                rotateVertexY(&transformed_vertex, obj->angle);

                f[3][0] = transformed_vertex.x;
                f[3][1] = transformed_vertex.y;
                f[3][2] = transformed_vertex.z;
                // f[3][0] = obj->s_vertices[vertex_index[3]]->x;
                // f[3][1] = obj->s_vertices[vertex_index[3]]->y;
                // f[3][2] = obj->s_vertices[vertex_index[3]]->z;

                glVertex3f(f[0][0], f[0][1], f[0][2]);
                glVertex3f(f[2][0], f[2][1], f[2][2]);
                glVertex3f(f[3][0], f[3][1], f[3][2]);
            }
            for (int i = 0; i < 3; i++) {
                glVertex3f(f[i][0], f[i][1], f[i][2]);
            }
    }
    glEnd();
}