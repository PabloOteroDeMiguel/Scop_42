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

void SaveVertices(t_object *obj, char *file) {
    int         fd;
    int         v_cont;
    char        *str;
    char        **line;
    t_vertex    *vertex;
    float        f[3];

    fd = open(obj->file, O_RDONLY);
    str = get_next_line(fd);
    v_cont = 0;
    while (str != NULL) {
        if (str[0] == 'v' && str[1] == ' ') {
            line = ft_split(str, ' ');
            vertex = (t_vertex *)malloc(sizeof(t_vertex));
            if (!vertex) {
                perror("Error al asignar memoria para el vértice");
                free(str);
                close(fd);
                return;
            }
            f[0] = strtof(line[1], NULL);
            vertex->x = f[0];
            f[1] = strtof(line[2], NULL);
            vertex->y = f[1];
            f[2] = strtof(line[3], NULL);
            vertex->z = f[2];
            //printf("%s --> %f, %f, %f\n", str, f[0], f[1], f[2]);
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
    float   f[4];
    int     fc_cont;

    fc_cont = 0;
    fd = open(obj->file, O_RDONLY);
    if (fd < 0) {
        perror("Error al abrir el archivo");
        return;
    }
    str = get_next_line(fd);
    f_cont = 0;
    while (str != NULL) {
        if (str[0] == 'f' && str[1] == ' ') {
            line = ft_split(str, ' ');
            if (!line) {
                free(line);
                str = get_next_line(fd);
                continue;
            }
            face = (t_face *)malloc(sizeof(t_face));
            if (!face) {
                perror("Error al asignar memoria para el vértice");
                free(str);
                close(fd);
                return;
            }
            f[0] = atoi(line[1]);
            face->x = f[0];
            f[1] = atoi(line[2]);
            face->y = f[1];
            f[2] = atoi(line[3]);
            face->z = f[2];
            if (line[4]){
                f[3] = atoi(line[4]);
                face->t = f[3];
            }
            else{
                face->t = 0; //Can be??
            }
            face->face_color = fc_cont;
            fc_cont++;
            if (fc_cont > 5)
                fc_cont = 0;
            obj->s_faces[f_cont] = face;
            f_cont++;   
            free(line);
        }
        str = get_next_line(fd);
    }
    close(fd);
}