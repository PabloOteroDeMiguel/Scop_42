/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkGLError.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:52:31 by potero-d          #+#    #+#             */
/*   Updated: 2024/03/20 11:33:11 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_GL_ERROR_H
#define CHECK_GL_ERROR_H

#include <GL/glew.h>
#include <iostream>

void checkGLError(const char* statement, const char* file, int line);

#define CHECK_GL_ERROR(statement) do { \
    statement; \
    checkGLError(#statement, __FILE__, __LINE__); \
} while (0)

#endif
