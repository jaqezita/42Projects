# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 13:14:23 by jaqribei          #+#    #+#              #
#    Updated: 2023/10/22 21:29:42 by jaqribei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = solong.h

CC = cc

FLAGS = -g3

LIBX = MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm

INCLUDES = -I MLX42/include/MLX42/ -I ./libft/ 

SRC = $(addprefix ./mandatory/,  so_long.c map_checker.c assets_handler.c \
	clear_memory.c mechanisms.c map_validation.c) 

SRC_OBJ = $(SRC:%.c=%.o)

BONUS = $(addprefix ./bonus/,  so_long_bonus.c map_checker_bonus.c \
	assets_handler_bonus.c clear_memory_bonus.c mechanisms_bonus.c map_validation_bonus.c) 

BONUS_OBJ = $(BONUS:%.c=%.o)

all: libft $(NAME)

$(NAME): $(SRC_OBJ)
	$(CC) $(FLAGS) $(SRC_OBJ) $(LIBX) ./libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES)

bonus: libft $(BONUS_OBJ)
	$(CC) $(FLAGS) $(BONUS_OBJ) $(LIBX) ./libft/libft.a -o $(NAME)

libft:
	make -C ./libft

clean:
	rm -f $(SRC_OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all libft bonus clean fclean re
