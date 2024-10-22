/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textureAndColor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:52:31 by potero            #+#    #+#             */
/*   Updated: 2024/02/19 18:52:53 by potero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "scop.h"

void generateRandomColor(float *r, float *g, float *b, int color) {
    *r = (float)rand() / RAND_MAX;
    *g = (float)rand() / RAND_MAX;
    *b = (float)rand() / RAND_MAX;
}

void generateBasicColor(float *r, float *g, float *b, int color) {
    switch (color) {
        case 0:
            *r = 1.0f; *g = 0.0f; *b = 0.0f; // Rojo
            break;
        case 1:
            *r = 0.0f; *g = 1.0f; *b = 0.0f; // Verde
            break;
        case 2:
            *r = 0.0f; *g = 0.0f; *b = 1.0f; // Azul
            break;
        case 3:
            *r = 1.0f; *g = 1.0f; *b = 0.0f; // Amarillo
            break;
        case 4:
            *r = 1.0f; *g = 0.0f; *b = 1.0f; // Magenta
            break;
        case 5:
            *r = 0.0f; *g = 1.0f; *b = 1.0f; // Cian
            break;
        default:
            *r = 1.0f; *g = 1.0f; *b = 1.0f; // Blanco por defecto
            break;
    }
}
void generateColor(float *r, float *g, float *b, int color, int type) {
    if (type == 0) {
        *r = 255.0f;
        *g = 255.0f;
        *b = 255.0f;
    }
    else if (type == 1) {
        // generateRandomColor(r, g, b);
        switch (color) {
        case 0:
            *r = 1.0f; *g = 0.0f; *b = 0.0f; // Rojo
            break;
        case 1:
            *r = 0.0f; *g = 1.0f; *b = 0.0f; // Verde
            break;
        case 2:
            *r = 0.0f; *g = 0.0f; *b = 1.0f; // Azul
            break;
        case 3:
            *r = 1.0f; *g = 1.0f; *b = 0.0f; // Amarillo
            break;
        case 4:
            *r = 1.0f; *g = 0.0f; *b = 1.0f; // Magenta
            break;
        case 5:
            *r = 0.0f; *g = 1.0f; *b = 1.0f; // Cian
            break;
        default:
            *r = 1.0f; *g = 1.0f; *b = 1.0f; // Blanco por defecto
            break;
    }
    }
    else if (type== 2){
        // generateColor(&r, &g, &b, color);
        *r = (float)rand() / RAND_MAX;
        *g = (float)rand() / RAND_MAX;
        *b = (float)rand() / RAND_MAX;
    } 
}  