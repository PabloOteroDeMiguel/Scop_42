/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:29:18 by potero-d          #+#    #+#             */
/*   Updated: 2024/03/20 11:30:49 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void freeObj(t_object *obj) {

    for (int i = 0; i < obj->num_vertices; i++){
        free(obj->s_vertices[i]);
    }
    for (int i = 0; i < obj->num_faces; i++){
        free(obj->s_faces[i]);
    }
    free(obj->s_vertices);
    free(obj->s_faces);
    free(obj->vertices);
    obj->num_vertices = 0;
}
