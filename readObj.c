/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readObj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 11:44:35 by pablo-d           #+#    #+#             */
/*   Updated: 2024/03/20 11:43:25 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "scop.h"

void countVerticesAndFaces(t_object *obj){
    int fd;
    char *str;
    fd = open(obj->file, O_RDONLY);
    str = get_next_line(fd);
    obj->num_faces = 0;
    obj->num_vertices = 0;
    while (str != NULL){
        if (str[0] == 'v' && str[1] == ' '){
            obj->num_vertices++;
        }
        else if (str[0] == 'f' && str[1] == ' '){
            obj->num_faces++;
        }
        //printf("%s\n", str);
        str = get_next_line(fd);
    }
}

void    saveVertices(t_object *obj){
    int fd;
    int num_vertices = 0;
    char *str;
    char **line;
    float v[3];

    fd = open(obj->file, O_RDONLY);
    str = get_next_line(fd);

    while (str != NULL) {
        if (str[0] == 'v' && str[1] == ' ') {
            line = ft_split(str, ' ');
        
            // Save vertices
            obj->vertices[num_vertices][0] = v[0];
            obj->vertices[num_vertices][1] = v[1];
            obj->vertices[num_vertices][2] = v[2];
            num_vertices++;

            free(line);
        }
        str = get_next_line(fd);
    }
}