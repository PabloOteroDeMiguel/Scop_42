/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textureAndColor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:52:31 by potero            #+#    #+#             */
/*   Updated: 2024/02/19 18:52:53 by potero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define STB_IMAGE_IMPLEMENTATION
#include "../include/stb_image.h"
#include "../include/Scop.h"

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

GLuint loadTexture(std::string filepath) {
    
    GLuint textureID;
    const char *path = filepath.c_str();
    CHECK_GL_ERROR(glGenTextures(1, &textureID));
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);
    if (!data) {
        fprintf(stderr, "Failed to load texture: %s\n", path);
        return 0;
    }
    else {
        printf("Chanel: %d\n", nrChannels);
        printf("Width: %d\n", width);
        printf("Height: %d\n", height);
        printf("Here -1\n");
        GLenum const fmt[] = {GL_RED, GL_RG, GL_RGB, GL_RGBA};
        printf("Format: %d\n", fmt[nrChannels-1]);
        CHECK_GL_ERROR(glBindTexture(GL_TEXTURE_2D, textureID));
        CHECK_GL_ERROR(glTexImage2D(GL_TEXTURE_2D, 0, fmt[nrChannels-1], width, height, 0, fmt[nrChannels-1], GL_UNSIGNED_BYTE, data));
        printf("Here 0\n");
        CHECK_GL_ERROR(glGenerateMipmap(GL_TEXTURE_2D));
        printf("Here 1\n");
        CHECK_GL_ERROR(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
        CHECK_GL_ERROR(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
        CHECK_GL_ERROR(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
        CHECK_GL_ERROR(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
        
        stbi_image_free(data);    
    }
    
    printf("Here 4\n");
    printf("TextureID: %i\n", textureID);
    return textureID;
}