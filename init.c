/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:16:46 by potero-d          #+#    #+#             */
/*   Updated: 2024/03/20 11:20:54 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "scop.h"

void initializeObject(t_object *obj) {

    obj->vertices = malloc(obj->num_vertices * sizeof(float[3]));
    if (obj->vertices == NULL) {
        exit(EXIT_FAILURE);
    }  
}
