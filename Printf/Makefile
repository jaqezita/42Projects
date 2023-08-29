# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 19:00:54 by jaqribei          #+#    #+#              #
#    Updated: 2023/08/29 02:03:42 by jaqribei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = libftprint.a

NAME = ft_printf

CC = cc

FLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c ft_int.c

OBJ = ${SRC:%.c=%.o}

all: ${NAME}

$(NAME): $(OBJ)

%.o: %.c
	${CC} ${FLAGS} -c ${SRC} -o ${NAME} 
# $(CC) $(FLAGS) -c $< -o $@
# ar rc $(NAME) $@

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
