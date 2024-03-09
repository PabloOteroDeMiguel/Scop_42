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

SOURCES = main.c errors.c \
			validateFile.c \
			gnl/get_next_line_utils.c gnl/get_next_line.c \

CC = gcc
CFLAGS = -I/usr/local/Cellar/glfw/3.4/include -I/usr/local/Cellar/glew/2.2.0_1/include -Imlx -Ilibft/
LDFLAGS = -L/usr/local/Cellar/glfw/3.4/lib -L/usr/local/Cellar/glew/2.2.0_1/lib -lglfw -lGLEW -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

LIBFT_PATH = libft/

OBJECTS=$(SOURCES:.c=.o)

NAME=scop

RM = rm -f

all: $(SOURCES) $(NAME)

$(NAME): $(OBJECTS)
		@make -C $(LIBFT_PATH) --silent
		$(CC) $(OBJECTS) $(LDFLAGS) -o $@  -I./libft -L./libft -lft

.c.o:
		$(CC) -c $(CFLAGS) $< -o $@ -I$(LIBFT_PATH)

clean:
	 $(RM) $(OBJECTS) $(NAME)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fcelan re

