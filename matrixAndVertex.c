/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixAndVertex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:51:53 by potero-d          #+#    #+#             */
/*   Updated: 2024/03/20 11:34:16 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void multiplyMatrixVector(float *v, float matrix[4][4])
{

    float result[4];
    for (int i = 0; i < 4; i++) {
        result[i] = v[0] * matrix[i][0] + v[1] * matrix[i][1] + v[2] * matrix[i][2] + v[3] * matrix[i][3];
    }
    for (int i = 0; i < 4; i++) {
        v[i] = result[i];
    }
}

void scaleVertex(t_vertex *v, float scale)
{
    float scale_matrix[4][4] = {
        {scale, 0, 0, 0},
        {0, scale, 0, 0},
        {0, 0, scale, 0},
        {0, 0, 0, 1}
    };

    float vertex[4] = {v->x, v->y, v->z, 1.0f};
    multiplyMatrixVector(vertex, scale_matrix);
    v->x = vertex[0];
    v->y = vertex[1];
    v->z = vertex[2];
}

void rotateVertexY(t_vertex *v, float angle) 
{

    float PI = 3.14159265;

    float angle_rad = angle * PI / 180.0f;
    float cos_angle = cos(angle_rad);
    float sin_angle = sin(angle_rad);

    float rotation_matrix[4][4] = {
        {cos_angle, 0, sin_angle, 0},
        {0, 1, 0, 0},
        {-sin_angle, 0, cos_angle, 0},
        {0, 0, 0, 1}
    };

    float vertex[4] = {v->x, v->y, v->z, 1.0f};
    multiplyMatrixVector(vertex, rotation_matrix);
    v->x = vertex[0];
    v->y = vertex[1];
    v->z = vertex[2];
}