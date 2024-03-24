# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 15:36:26 by jaqribei          #+#    #+#              #
#    Updated: 2024/03/23 21:09:42 by jaqribei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror -pthread 

INCLUDE = philo.h

NAME = philo

SRC = main.c utils.c validate_args.c routine.c init.c execution.c
		

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "\033[32m[✓] \033[1m\033[1m$(NAME) created\033[0m"

%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "\033[32m[✓] \033[1m\033[1m$@ created\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "\033[31m[✗] \033[1m\033[1mObjects removed\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m[✗] \033[1m\033[1m$(NAME) removed\033[0m"

re:
	@make fclean
	@make all

norm:
	@norminette $(SRC) $(INCLUDE)

.PHONY: all clean fclean re norm