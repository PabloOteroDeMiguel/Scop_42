/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:52:31 by potero-d          #+#    #+#             */
/*   Updated: 2024/03/20 11:32:56 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include "gnl/get_next_line.h"  
# include "libft/libft.h"
# include "structs.h"

//main

//errors
void	error_no(int e);

//validateFile
void    validateFile(char *file);
void	file_name(char *str);

//readObj
void    countVerticesAndFaces(t_object *obj);
void    CenterObject(t_object *obj);

//printObj
//void    printVertices(char *file, t_object *obj);
//void    printFaces(char *file, t_object *obj);
void    printVertices(t_object *obj);
void    printFaces(t_object *obj);

//saveObj
void    SaveVertices(t_object *obj, char *file);
void    SaveFaces(t_object *obj);

//init
void    initializeObject(t_object *obj);

//free
void    freeObj(t_object *obj);

//matrixAndVertex
void    multiplyMatrixVector(float *v, float matrix[4][4]);
void    scaleVertex(t_vertex *v, float scale);
void    rotateVertexY(t_vertex *v, float angle);
void    rotateVertexX(t_vertex *v, float angle);

//textureAndColor
void    generateColor(float *r, float *g, float *b, int color, int type);
// void    generateRandomColor(float *r, float *g, float *b);
// void    generateColor(float *r, float *g, float *b, int color);

#endif