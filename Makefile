# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: potero-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 19:20:44 by potero-d          #+#    #+#              #
#    Updated: 2024/02/19 15:13:33 by potero-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = main.c

CC = gcc
CFLAGS = -I/usr/local/Cellar/glfw/3.4/include -I/usr/local/Cellar/glew/2.2.0_1/include -Imlx -Ilibft/
LDFLAGS = -L/usr/local/Cellar/glfw/3.4/lib -L/usr/local/Cellar/glew/2.2.0_1/lib -lglfw -lGLEW -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

OBJECTS=$(SOURCES:.c=.o)

NAME=scop

RM = rm -f

all: $(SOURCES) $(NAME)

$(NAME): $(OBJECTS)
		$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.c.o:
		$(CC) -c $(CFLAGS) $< -o $@

clean:
	 $(RM) $(OBJECTS) $(NAME)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fcelan re

