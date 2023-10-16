# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 13:14:23 by jaqribei          #+#    #+#              #
#    Updated: 2023/10/15 03:25:16 by jaqribei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = solong.h

CC = cc

FLAGS = -g3

LIBX = MLX42/build/libmlx42.a -I MLX42/include/MLX42/MLX42.h -ldl -lglfw -pthread -lm

SRC = so_long.c map_checker.c assets_handler.c clear_memory.c mechanisms.c ending_game.c

SRC_OBJ = $(SRC:%.c=%.o)

all: libft $(NAME)

$(NAME): $(SRC_OBJ)
	$(CC) $(FLAGS) $(SRC_OBJ) $(LIBX) ./libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

libft:
	make -C ./libft

clean:
	rm -f $(SRC_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all libft bonus clean fclean re
