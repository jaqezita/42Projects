# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 02:47:29 by jaqribei          #+#    #+#              #
#    Updated: 2023/10/20 04:11:44 by jaqribei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S_NAME = server
C_NAME = client

header = ./libft/libft.a -I ./libft/libft.h

CC = cc

FLAGS = -Wall -Wextra -Werror -g3

S_SRC = server.c

C_SRC = client.c

S_OBJ = $(S_SRC:.c=.o)

C_OBJ = $(C_SRC:.c=.o)

all: $(S_NAME) $(C_NAME)

$(S_NAME): libft $(S_OBJ)
	@$(CC) $(FLAGS) $(S_OBJ) $(header) -o $(S_NAME)

$(C_NAME): libft $(C_OBJ)
	@$(CC) $(FLAGS) $(C_OBJ) $(header) -o $(C_NAME)

libft:
	@make -C ./libft

clean:
	@rm -f $(S_OBJ) $(C_OBJ)
	@make clean -C ./libft

fclean: clean
	@rm -f $(S_NAME) $(C_NAME)
	@make fclean -C ./libft

re: fclean all

norm:
	@norminette
	@echo "Norminette done!"

phony: all clean fclean re libft bonus 