/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveObj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:52:31 by potero            #+#    #+#             */
/*   Updated: 2024/06/08 18:52:53 by potero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void SaveVertices(t_object *obj) {
    int         fd;
    int         v_cont;
    char        *str;
    char        **line;
    t_vertex    *vertex;

    fd = open(obj->file, O_RDONLY);
    str = get_next_line(fd);
    v_cont = 0;
    while (str != NULL) {
        if (str[0] == 'v' && str[1] == ' ') {
            line = ft_split(str, ' ');
            vertex->x  = strtof(line[1], NULL);
            vertex->y= strtof(line[2], NULL);
            vertex->z  = strtof(line[3], NULL);
            obj->s_vertices[v_cont] = vertex;
            v_cont++;
            free(line);
        }
        str = get_next_line(fd);
    }
    close(fd);
}

void SaveFaces(t_object *obj) {
    int     fd;
    int     f_cont;
    char    *str;
    char    **line;
    t_face  *face;

    fd = open(obj->file, O_RDONLY);
    str = get_next_line(fd);

    while (str != NULL) {
        if (str[0] == 'f' && str[1] == ' ') {
            line = ft_split(str, ' ');
            face->x  = strtof(line[1], NULL);
            face->y= strtof(line[2], NULL);
            face->z  = strtof(line[3], NULL);
            face->t  = strtof(line[4], NULL);
            obj->s_faces[f_cont] = face;
            f_cont++;   
            free(line);
        }
        str = get_next_line(fd);
    }
    close(fd);
}