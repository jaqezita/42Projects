# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 13:14:23 by jaqribei          #+#    #+#              #
#    Updated: 2023/10/23 21:43:17 by jaqribei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS_NAME = so_long_bonus

HEADER = solong.h

CC = cc 

FLAGS = -g3 -Wall -Wextra -Werror

LIBX = MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm

INCLUDES = -I MLX42/include/MLX42/ -I ./libft/ 

SRC = $(addprefix ./mandatory/,  so_long.c map_checker.c assets_handler.c \
	clear_memory.c mechanisms.c map_validation.c utils.c) 

SRC_OBJ = $(SRC:%.c=%.o)

BONUS = $(addprefix ./bonus/,  so_long_bonus.c map_checker_bonus.c \
	assets_handler_bonus.c clear_memory_bonus.c mechanisms_bonus.c \
	map_validation_bonus.c utils_bonus.c) 

BONUS_OBJ = $(BONUS:%.c=%.o)

all: libft $(NAME)

$(NAME): $(SRC_OBJ)
	$(CC) $(FLAGS) $(SRC_OBJ) $(LIBX) ./libft/libft.a -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES)

bonus: libft $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(FLAGS) $(BONUS_OBJ) $(LIBX) ./libft/libft.a -o $(BONUS_NAME)

libft:
	@make -C ./libft

clean:
	rm -f $(SRC_OBJ) $(BONUS_OBJ)
	@make clean -C ./libft

fclean: clean
	rm -f $(NAME) $(BONUS_NAME) libft/libft.a

re: fclean all 

.PHONY: all libft bonus clean fclean re
