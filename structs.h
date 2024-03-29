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

typedef struct s_object
{
	char		*file;
	int			num_vertices;
	int			num_faces;
	
	float		(*vertices)[3];
	GLFWwindow	*win;

}	t_object;

#endif