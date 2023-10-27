# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 02:47:29 by jaqribei          #+#    #+#              #
#    Updated: 2023/10/26 23:50:28 by jaqribei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#+++++++++ COLORS +++++++++
CYAN = \033[1;36m
RESET = \033[0m
#+++++++++ COLORS +++++++++

S_NAME = server
C_NAME = client

CC = cc

FLAGS = -Wall -Wextra -Werror -g3

INCLUDES = -I ./libft/

S_SRC = server.c

S_OBJ = $(S_SRC:%.c=%.o)

C_SRC = client.c

C_OBJ = $(C_SRC:%.c=%.o)

all: norm libft $(S_NAME) $(C_NAME)

$(S_NAME): $(S_OBJ) | libft
	$(CC) $(FLAGS) $(S_OBJ) ./libft/libft.a -o $(S_NAME)

$(C_NAME): $(C_OBJ) | libft
	$(CC) $(FLAGS) $(C_OBJ) $(header) ./libft/libft.a -o $(C_NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES)

libft:
	@make -C ./libft

clean:
	@rm -f $(S_OBJ) $(C_OBJ)
	@make clean -C ./libft

fclean: clean
	@rm -f $(S_NAME) $(C_NAME)
	@make fclean -C ./libft
	@echo "$(CYAN)$(S_NAME) && $(C_NAME) removed.$(RESET)"

re: fclean all

norm:
	norminette -R CheckForbiddenSource
	@echo "$(CYAN)NORMINETTE OK $(RESET)"

.PHONY: all clean fclean re libft bonus 