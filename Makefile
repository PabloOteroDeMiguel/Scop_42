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

SRCS = main.c\
	   \
	   \
	   \

LIBFT_PATH = libft/
GLEW_PATH = /Users/potero-d/.brew/Cellar/glew/2.2.0_1/include/
GLFW_PATH =/Users/potero-d/.brew/Cellar/glfw/3.3.9/include
OBJS = $(SRCS:.c=.o)

NAME = scop

CC = gcc

CFLAGS = -Wall -Wextra -Werror

%.o:%.c
		$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o) -I$(LIBFT_PATH) -I$(GLEW_PATH) -I$(GLFW_PATH)
RM = rm -f

$(NAME): $(OBJS)
		@make -C $(LIBFT_PATH) --silent
		$(CC) $(CFLAGS) $(OBJS) -Imlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -I./libft -L./libft -lft -I$(GLEW_PATH) -I$(GLFW_PATH)
	#	$(CC) $(CFLAGS) $(OBJS) -lmlx -L/usr/X11/lib -lXext -lX11 -lm -o $(NAME)  -I./libft -L./libft -lft -I$(GLEW_PATH) -I$(GLFW_PATH)

all: $(NAME)  


sanitize: $(OBJS)
		@make -C $(LIBFT_PATH)  --silent
		$(CC) $(CFLAGS) $(OBJS) -Imlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -I./libft -L./libft -lft -fsanitize=address -g3 -O3

clean:
			$(RM) $(OBJS)
			@make -C $(LIBFT_PATH) clean --silent

fclean: clean
			$(RM) $(NAME)
			@make -C $(LIBFT_PATH) fclean --silent

re: fclean $(NAME)

.PHONY: all clean fcelan re
