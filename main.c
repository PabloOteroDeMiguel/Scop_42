/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:52:31 by potero            #+#    #+#             */
/*   Updated: 2024/02/19 18:52:53 by potero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

// int main(int argc, char** argv){

//     if (argc != 2)
// 	{
// 		ft_putstr_fd("Error\nWrong number of arguments\n", 1);
// 		exit(0);
// 	}
//     else {
//         ft_putstr_fd(argv[1], 1);
//     }
// }

#include <GL/glew.h>
#include <GLFW/glfw3.h>
void Render(void)
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
int main(void) {
    GLFWwindow* win;
    if(!glfwInit()){
        return -1;
    }
    win = glfwCreateWindow(640, 480, "OpenGL Base Project", NULL, NULL);
    if(!win)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    if(!glewInit())
    {
        return -1;
    }
    glfwMakeContextCurrent(win);
    while(!glfwWindowShouldClose(win)){
        Render();
        glfwSwapBuffers(win);
        glfwPollEvents();
    }
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}