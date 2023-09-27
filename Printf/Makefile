# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 19:00:54 by jaqribei          #+#    #+#              #
#    Updated: 2023/09/07 20:48:23 by jaqribei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Werror -Wextra -g3

NAME = libftprintf.a

SRC = ft_hexa.c ft_numbers.c ft_printf.c ft_ptr.c ft_str_chr.c ft_unsigned_number.c ft_check_specifier.c

OBJ = $(SRC:%.c=%.o)

BONUS_SRC = ft_hexa_flag_bonus.c ft_printf_bonus.c ft_numbers_bonus.c ft_ptr_bonus.c ft_str_chr_bonus.c ft_unsigned_number_bonus.c ft_check_specifier.c

BONUS_OBJ = $(BONUS_SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(if $(wildcard ft_printf_bonus.o), ,$(OBJ))

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
	ar rcs $(NAME) $@

bonus: $(if $(wildcard ft_check_specifier.o), $(BONUS_OBJ), all $(BONUS_OBJ))
	$(if $(wildcard ft_printf.o), $(shell rm -f ft_printf.o && ar -d $(NAME) ft_printf.o))
	
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	@make --no-print-directory

.PHONY: all clean fclean re bonus
