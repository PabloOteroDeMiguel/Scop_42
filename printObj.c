/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printObj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:51:53 by potero-d          #+#    #+#             */
/*   Updated: 2024/03/20 11:34:16 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void printVertices(char *file) {
    int fd;
    char *str;
    char **line;
    float v[3];

    fd = open(file, O_RDONLY);
    str = get_next_line(fd);

    glBegin(GL_POINTS);
    while (str != NULL) {
        if (str[0] == 'v' && str[1] == ' ') {
            line = ft_split(str, ' ');
            v[0] = strtof(line[1], NULL);
            v[1] = strtof(line[2], NULL);
            v[2] = strtof(line[3], NULL);
            glVertex3f(v[0], v[1], v[2]);
            free(line);
        }
        str = get_next_line(fd);
    }
    glEnd();
    close(fd);
}

void printFaces(t_object *obj, char* file) {
    int fd;
    int vertex_index;
    char *str;
    char **line;
    GLfloat f[4][3];
    //printf("fd-> %s\n", obj->file);
    fd = open(file, O_RDONLY);
    str = get_next_line(fd);

    glBegin(GL_TRIANGLES);
    //printf("%s -->\n", str);
    while (str != NULL) {
        //printf("%s -->\n", str);
        if (str[0] == 'f' && str[1] == ' ') {
            line = ft_split(str, ' ');
            for (int i = 1; i <= 3; i++) {
                vertex_index = atoi(line[i]) - 1;
                if(!vertex_index){
                    continue;
                }
                f[i - 1][0] = obj->s_vertices[vertex_index]->x;          
                f[i - 1][1] = obj->s_vertices[vertex_index]->y;
                f[i - 1][2] = obj->s_vertices[vertex_index]->z;
                //printf("%i --> %f, %f, %f\n", vertex_index, f[i - 1][0], f[i - 1][1], f[i - 1][2]);              
            }
            if (line[4] && line[4] != NULL){
                vertex_index = atoi(line[4]) - 1;
                f[3][0] = obj->s_vertices[vertex_index]->x;
                f[3][1] = obj->s_vertices[vertex_index]->y;
                f[3][2] = obj->s_vertices[vertex_index]->z;
                glVertex3f(f[3][0], f[3][1], f[3][2]);
                glVertex3f(f[1][0], f[1][1], f[1][2]);
                glVertex3f(f[2][0], f[2][1], f[2][2]);
            }
            for (int i = 0; i < 3; i++) {
                glVertex3f(f[i][0], f[i][1], f[i][2]);
            }
            free(line);
        }
        str = get_next_line(fd);
    }
    glEnd();
    close(fd);
}