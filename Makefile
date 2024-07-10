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

SOURCES = main.c errors.c init.c\
			validateFile.c readObj.c printObj.c saveObj.c matrixAndVertex.c\
			gnl/get_next_line_utils.c gnl/get_next_line.c \
			free.c

CC = gcc
#CFLAGS = -I/usr/local/Cellar/glfw/3.4/include -I/usr/local/Cellar/glew/2.2.0_1/include -Imlx -Ilibft/
#LDFLAGS = -L/usr/local/Cellar/glfw/3.4/lib -L/usr/local/Cellar/glew/2.2.0_1/lib -lglfw -lGLEW -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
CFLAGS = -I/home/potero-d/.brew/Cellar/glfw/3.4/include -I/home/potero-d/.brew/Cellar/glew/2.2.0_1/include -Imlx -Ilibft/
LDFLAGS = -L/home/potero-d/.brew/Cellar/glfw/3.4/lib -L/home/potero-d/.brew/Cellar/glew/2.2.0_1/lib -lGLEW -lglfw -lGL -lm

LIBFT_PATH = libft/

OBJECTS=$(SOURCES:.c=.o)

NAME=scop

RM = rm -f

all: $(SOURCES) $(NAME)

$(NAME): $(OBJECTS)
		@make -C $(LIBFT_PATH) --silent
		$(CC) $(OBJECTS) $(CFLAGS) $(LDFLAGS) -o $@  -I./libft -L./libft -lft

.c.o:
		$(CC) -c $(CFLAGS) $(LDFLAGS) $< -o $@ -I$(LIBFT_PATH)

sanitize: CFLAGS += -fsanitize=address
sanitize: LDFLAGS += -fsanitize=address
sanitize: $(OBJECTS)
	@make -C $(LIBFT_PATH) --silent
	$(CC) $(OBJECTS) $(CFLAGS) $(LDFLAGS) -o $(NAME) -I./libft -L./libft -lft

clean:
	 $(RM) $(OBJECTS) $(NAME)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fcelan re

