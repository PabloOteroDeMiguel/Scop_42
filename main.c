/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:52:31 by potero-d          #+#    #+#             */
/*   Updated: 2024/03/20 11:33:11 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void    input_key(t_object* obj) {

    if (glfwGetKey(obj->win, GLFW_KEY_D) == GLFW_PRESS) {
        obj->angle_x += 5.0f;
    }
    else if (glfwGetKey(obj->win, GLFW_KEY_A) == GLFW_PRESS) {
        obj->angle_x -= 5.0f;
    }
    else if (glfwGetKey(obj->win, GLFW_KEY_E) == GLFW_PRESS) {
        obj->scale += 0.1f;
    }
    else if (glfwGetKey(obj->win, GLFW_KEY_Q) == GLFW_PRESS) {
        obj->scale -= 0.1f;
        if (obj->scale < 0) { //Para que no se invierta
            obj->scale = 0;
        }
    }
    else if (glfwGetKey(obj->win, GLFW_KEY_W) == GLFW_PRESS) {
        obj->angle_y += 5.0f; // Rotar hacia arriba
    }
    else if (glfwGetKey(obj->win, GLFW_KEY_S) == GLFW_PRESS) {
        obj->angle_y -= 5.0f; // Rotar hacia abajo
    }
    else if (glfwGetKey(obj->win, GLFW_KEY_T) == GLFW_PRESS) {
        obj->color += 1;

        if (obj->color >2) {
            obj->color = 0;
        }
    }
    else if (glfwGetKey(obj->win, GLFW_KEY_1) == GLFW_PRESS) {
        if (obj->color == 1) {
            obj->color = 0;
        }
        else {
            obj->color = 1;
        }
    }
    else if (glfwGetKey(obj->win, GLFW_KEY_2) == GLFW_PRESS) {
        if (obj->color == 2) {
            obj->color = 0;
        }
        else {
            obj->color = 2;
        }
    }
}

int main(int argc, char** argv) 
{
    int fd;
    char *str;
    t_object *obj;
    if (argc != 2){
       error_no(1);
    }
    
    obj = (t_object *)malloc(sizeof(t_object));
    if (!obj) {
        fprintf(stderr, "Error\n");
        return EXIT_FAILURE;
    }
    obj->file = argv[1];
    obj->scale = 1;
    obj->angle_x = 0.0f;
    obj->angle_y = 0.0f;
    obj->color = 0;
    validateFile(argv[1]); //check file
    countVerticesAndFaces(obj);
    initializeObject(obj);
    printf("Vertices-->\t%i\n", obj->num_vertices);
    printf("Faces----->\t%i\n", obj->num_faces);

    //Create memory
    obj->s_vertices = (t_vertex **)malloc(obj->num_vertices * sizeof(t_vertex*));
    obj->s_faces = (t_face **)malloc(obj->num_faces * sizeof(t_face*));
    if (obj->s_faces == NULL || obj->s_faces == NULL){
        error_no(2);
    }

    SaveVertices(obj, argv[1]);
    CenterObject(obj);
    // int i = 0;
    // while (i < obj->num_vertices){
    //     printf("v[%i] --> (%f, %f, %f)\n", i, obj->s_vertices[i]->x, obj->s_vertices[i]->y, obj->s_vertices[i]->z);
    //     i++;
    // }
    SaveFaces(obj);
    
    GLFWwindow* win;
    
    if(!glfwInit()){
        return -1;
    }
    obj->win = glfwCreateWindow(1280, 720, "SCOP", NULL, NULL);   
    if(!obj->win)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    if(!glewInit())
    {
        return -1;
    }
    
    glfwMakeContextCurrent(obj->win);
    while(!glfwWindowShouldClose(obj->win)){
        input_key(obj);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        printVertices(obj);
        printFaces(obj);
        glfwSwapBuffers(obj->win);
        glfwPollEvents();
    }
    glfwTerminate();
    freeObj(obj);
    exit(EXIT_SUCCESS);
    
    return (0);
}
