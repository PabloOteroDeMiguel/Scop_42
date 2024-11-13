# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: potero-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 19:20:44 by potero-d          #+#    #+#              #
#    Updated: 2024/03/20 11:31:00 by potero-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = src/main.cpp\
		src/Object.cpp src/checkGLError.cpp\
		src/validateFile.cpp src/matrixAndVertex.cpp src/textureAndColor.cpp\
		src/printVertices.cpp src/printFaces.cpp src/inputKey.cpp\
# SOURCES = src/main.cpp src/errors.cpp src/init.cpp\
#             src/validateFile.cpp src/readObj.cpp src/printObj.cpp src/saveObj.cpp src/matrixAndVertex.cpp src/textureAndColor.cpp\
#             src/gnl/get_next_line_utils.cpp src/gnl/get_next_line.cpp \
#             src/free.cpp src/render.cpp src/checkGLError.cpp

CC = g++
# CFLAGS = -Wall -Werror -Wextra -Ilibs/glfw/include -Ilibs/glew/include -Ilibs/stb -Imlx
CFLAGS = -std=c++17 -Wall -Werror -Wextra -Ilibs/glew/include -DGLEW_STATIC -I./inc
LDFLAGS =-Llibs/glew/lib -lGLEW -lGLU -lglfw -lGL -lX11 -lXrandr -lpthread -ldl -Wl,-rpath=libs/glew/lib
SRC_DIR = src
# LDFLAGS = -Llibs/glfw/lib -Llibs/glew/lib -lGLEW -lglfw -lGL -lm


OBJECTS=$(SOURCES:.cpp=.o)

NAME=scop

RM = rm -f

all: $(SOURCES) $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(LDFLAGS) -o $(NAME)

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJECTS)
		
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re