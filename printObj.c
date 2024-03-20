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

// void printVertices(char *file, t_object *obj) {
    
//     int vertices;
//     float v[3];
//     int fd;
//     int  cont = 0;
//     char *str;
//     char **line;
//     char *endptr;
    
//     fd = open(file, O_RDONLY);
//     str = get_next_line(fd);
//     vertices = obj->vertices;
    
//     glBegin(GL_POINTS);
//     while (str != NULL || cont < vertices){
//         if (str[0] == 'v' && str[1] == ' '){
//             line = ft_split(str, ' ');
//             v[0] = strtof(line[1], &endptr);
//             v[1] = strtof(line[2], &endptr);
//             v[2] = strtof(line[3], &endptr);
            
//             //printf("S[%i]\t(%s, %s , %s)\n", cont, line[1], line[2], line[3]);
//             printf("V[%i]\t(%f, %f , %f)\n", cont, v[0], v[1], v[2]);
//             glVertex3f(v[0], v[1], v[2]);
//             cont++;
//             free(line);
//         }
//         // else if (str[0] == 'f' && str[1] == ' '){
//         //     obj->faces++;
//         // }
//         str = get_next_line(fd);
//     }
//     close(fd);
//     glEnd();
// }

// void printFaces(char *file, t_object *obj) {
    
//     int faces;
//     float f[3];
//     int fd;
//     int  cont = 0;
//     char *str;
//     char **line;
//     char *endptr;
    
//     fd = open(file, O_RDONLY);
//     str = get_next_line(fd);
//     faces = obj->faces;
    
//     glBegin(GL_TRIANGLES);
//     while (str != NULL || cont < faces){
//         if (str[0] == 'f' && str[1] == ' '){
//             line = ft_split(str, ' ');
//             f[0] = strtof(line[1], &endptr);
//             f[1] = strtof(line[2], &endptr);
//             f[2] = strtof(line[3], &endptr);
            
//             //printf("S[%i]\t(%s, %s , %s)\n", cont, line[1], line[2], line[3]);
//             printf("F[%i]\t(%f, %f , %f)\n", cont, f[0], f[1], f[2]);
//             for (int j = 0; j < 3; j++) { 
//                 //int vertex_index = faces[i][j] - 1; // 1-indexed
//                 glVertex3f(f[0], f[1], f[2]);
//             }
//             cont++;
//             free(line);
//         }
//         // else if (str[0] == 'f' && str[1] == ' '){
//         //     obj->faces++;
//         // }
//         str = get_next_line(fd);
//     }
//     close(fd);
//     glEnd();
// }

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

void printFaces(t_object *obj) {
    int fd;
    char *str;
    char **line;
    float f[3][3];

    fd = open(obj->file, O_RDONLY);
    str = get_next_line(fd);

    glBegin(GL_TRIANGLES);
    while (str != NULL) {
        if (str[0] == 'f' && str[1] == ' ') {
            line = ft_split(str, ' ');
            for (int i = 1; i <= 3; i++) {
                char *endptr;
                int vertex_index = strtol(line[i], &endptr, 10) - 1;
                for (int j = 0; j < 3; j++) {
                    f[i - 1][j] = obj->vertices[vertex_index][j];
                }
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