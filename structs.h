/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 11:50:14 by potero-d          #+#    #+#             */
/*   Updated: 2024/03/20 11:22:49 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "scop.h"

typedef struct s_vertex
{
	GLfloat		x;
	GLfloat		y;
	GLfloat		z;
}	t_vertex;

typedef struct s_face
{
	GLfloat		x;
	GLfloat		y;
	GLfloat		z;
	GLfloat		t;
	int			face_color;
}	t_face;


typedef struct s_object
{
	char		*file;
	int			num_vertices;
	int			num_faces;
	int			color;
	
	float		(*vertices)[3];
	float		scale;
	float		angle_x;
	float		angle_y;
	
	t_vertex	**s_vertices;
	t_face		**s_faces;
	GLFWwindow	*win;

}	t_object;

#endif