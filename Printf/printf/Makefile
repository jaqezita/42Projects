# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 19:00:54 by jaqribei          #+#    #+#              #
#    Updated: 2023/09/04 18:58:01 by jaqribei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Werror -Wextra -g3

NAME = libftprintf.a

# NAME = ft_printf

SRC = ft_check_specifier_type.c ft_hexa_low.c ft_hexa_upper.c ft_numbers.c  ft_printf.c ft_ptr.c ft_str_chr.c ft_unsigned_number.c main.c

OBJ = ${SRC:%.c=%.o}

NORM = norminette -R CheckForbiddenSourceHeader

all: $(NAME)

$(NAME): $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I.
	ar rcs $(NAME) $@

norm:
	${NORM} ${SRC}

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
