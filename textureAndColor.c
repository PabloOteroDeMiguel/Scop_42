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

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
# include "scop.h"


void generateRandomColor(float *r, float *g, float *b) {
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
        generateBasicColor(r, g, b, color);
    }
    else if (type== 2){
        generateRandomColor(r, g, b);
    } 
} 

GLuint loadTexture(const char *filepath) {
    int width, height, nrChannels;
    unsigned char *data = stbi_load(filepath, &width, &height, &nrChannels, 0);
    if (!data) {
        fprintf(stderr, "Failed to load texture: %s\n", filepath);
        return 0;
    }

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);

    return texture;
}