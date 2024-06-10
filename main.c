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

float angleY = 0.0f;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    printf("Press -> %c\n", key);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (key == GLFW_KEY_D && action == GLFW_PRESS) {
        // Incrementar el ángulo de rotación al presionar 'd'
        angleY += 5.0f; // Puedes ajustar la velocidad de rotación aquí
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    }else if (key == GLFW_KEY_A && action == GLFW_PRESS) {
        // Decrementar el ángulo de rotación al presionar 'a'
        angleY -= 5.0f; // Puedes ajustar la velocidad de rotación aquí
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    }
}

void Render()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    {
        glColor3f(1.0,0.0,0.0);
        glVertex2f(0, .5);
        glColor3f(0.0,1.0,0.0);
        glVertex2f(-.5,-.5);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(.5, -.5);
    }
    glEnd();
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
    int i = 0;
    while (i < obj->num_vertices){
        printf("v[%i] --> (%f, %f, %f)\n", i, obj->s_vertices[i]->x, obj->s_vertices[i]->y, obj->s_vertices[i]->z);
        i++;
    }
    //SaveFaces(obj);
    //printf("HERE3\n");
    GLFWwindow* win;
    
    if(!glfwInit()){
        return -1;
    }
    obj->win = glfwCreateWindow(640, 480, "SCOP", NULL, NULL);
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
        //Render();
        printVertices(obj->file);
        printFaces(obj, argv[1]);
        glfwSwapBuffers(obj->win);
        //glfwSwapBuffers(win);
        glfwPollEvents();
        glfwSetKeyCallback(obj->win, key_callback);
        
    }
    glfwTerminate();
    freeObj(obj);
    exit(EXIT_SUCCESS);
    
    return (0);
}
