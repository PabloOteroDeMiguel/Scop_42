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
    t_object obj;
    if (argc != 2){
       error_no(1);
    }
    
    obj.file = argv[1];
    validateFile(argv[1]); //check file
    countVerticesAndFaces(&obj);
    initializeObject(&obj);
    printf("Vertices-->\t%i\n", obj.num_vertices);
    printf("Faces----->\t%i\n", obj.num_faces);

    //Create memory
    obj.s_vertices = (t_vertex **)malloc(obj.num_vertices * sizeof(t_vertex*));
    obj.s_faces = (t_face **)malloc(obj.num_faces * sizeof(t_face*));
    if (obj.s_faces == NULL || obj.s_faces == NULL){
        error_no(2);
    }
    //SaveVertices(&obj);
    //SaveFaces(&obj);
    //GLFWwindow* win;
    if(!glfwInit()){
        return -1;
    }
    obj.win = glfwCreateWindow(640, 480, "SCOP", NULL, NULL);
    if(!obj.win)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    if(!glewInit())
    {
        return -1;
    }
    glfwMakeContextCurrent(obj.win);
    while(!glfwWindowShouldClose(obj.win)){
        //Render();
        printVertices(obj.file);
        printFaces(&obj);
        glfwSwapBuffers(obj.win);
        glfwPollEvents();
    }
    glfwTerminate();
    freeObj(&obj);
    exit(EXIT_SUCCESS);
    
    return (0);
}
