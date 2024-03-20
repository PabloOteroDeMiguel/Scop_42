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
# include <fcntl.h>
# include "gnl/get_next_line.h"  
# include "libft.h"
# include "structs.h"

//main

//errors
void	error_no(int e);

//validateFile
void    validateFile(char *file);
void	file_name(char *str);

//readObj
void    countVerticesAndFaces(t_object *obj);

//printObj
//void    printVertices(char *file, t_object *obj);
//void    printFaces(char *file, t_object *obj);
void    printVertices(char *file);
void    printFaces(t_object *obj);

//init
void    initializeObject(t_object *obj);

//free
void    freeObj(t_object *obj);
#endif