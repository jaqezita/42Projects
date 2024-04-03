# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 14:10:02 by jaqribei          #+#    #+#              #
#    Updated: 2024/04/03 15:31:44 by jaqribei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#*********************************** COLORS ***********************************#
CYAN = \033[1;36m
GREEN = \033[1;32m
RESET = \033[0m
#*********************************** COLORS ***********************************#
NAME = tests

CC = cc

FLAGS = -g3

INCLUDES = tests.h

SRC = tests.c tuples.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -lm -o $(NAME)
	@echo "$(GREEN)[✓] $(RESET)$(CYAN)$(NAME) created$(RESET)"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDES)

# libft:
# 	@make -C ./libft
# 	@echo "$(GREEN)[✓] $(RESET)$(CYAN)libft created$(RESET)"

run: re all
	@./$(NAME)

gdb: re all
	@gdb ./$(NAME)

clean:
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)
	@echo "$(CYAN)$(NAME) removed.$(RESET)"

re: fclean all

norm:
	@norminette -R CheckForbiddenSource
	@echo "$(CYAN)NORMINETTE OK $(RESET)"

.PHONY: all clean fclean re 