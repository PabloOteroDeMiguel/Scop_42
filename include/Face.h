#ifndef FACE_H
# define FACE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

struct Face
{
	GLfloat		x;
	GLfloat		y;
	GLfloat		z;
	GLfloat		t;
	int			face_color;
};

#endif