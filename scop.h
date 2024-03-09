#ifndef SCOP_H
# define SCOP_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"  
# include "libft.h"

//main

//errors
void	error_no(int e);

//validateFile
void    validateFile(char *file);
void	file_name(char *str);

#endif