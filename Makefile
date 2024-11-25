# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pablo <pablo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 19:20:44 by potero-d          #+#    #+#              #
#    Updated: 2024/11/25 10:48:13 by pablo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = src/main.cpp src/instructions.cpp\
		src/Object.cpp src/checkGLError.cpp\
		src/validateFile.cpp src/matrixAndVertex.cpp src/textureAndColor.cpp\
		src/printVertices.cpp src/printFaces.cpp src/inputKey.cpp src/utils.cpp\

CC = g++
CFLAGS = -std=c++17 -Wall -Werror -Wextra -Ilibs/glew/include -DGLEW_STATIC -I./inc
LDFLAGS =-Llibs/glew/lib -lGLEW -lGLU -lglfw -lGL -lX11 -lXrandr -lpthread -ldl -Wl,-rpath=libs/glew/lib
SRC_DIR = src


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