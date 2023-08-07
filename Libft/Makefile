# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/22 19:30:18 by jaqribei          #+#    #+#              #
#    Updated: 2023/08/07 02:50:07 by jaqribei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c \

BONUS_OBJ = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o ft_lstdelone.o \
	ft_lstclear.o ft_lstiter.o ft_lstmap.o \

# BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
# 	ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

# BONUS_OBJ = ft_lstnew_bonus.o ft_lstadd_front_bonus.o ft_lstsize_bonus.o ft_lstlast_bonus.o ft_lstadd_back_bonus.o \
# 	ft_lstdelone_bonus.o ft_lstclear_bonus.o ft_lstiter_bonus.o ft_lstmap_bonus.o \

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 
	ar rcs $(NAME) $@

bonus: $(BONUS_OBJ)

$(BONUS_OBJ): $(BONUS_SRC)
	$(CC) $(CFLAGS) -c $(BONUS_SRC)
	ar rc $(NAME) $(BONUS_OBJ)

norm:
	norminette $(SRC) 
	
clean: 
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: rm -f all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

.PHONY: all clean fclean re

# CC = cc
# CFLAGS = -Wall -Wextra -Werror

# NAME = libft.a

# SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
#     ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
#     ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
#     ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
#     ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
# 	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
# 	ft_putendl_fd.c ft_putnbr_fd.c \

# OBJ = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
#     ft_strlen.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o \
#     ft_strlcpy.o ft_strlcat.o ft_toupper.o ft_tolower.o ft_strchr.o \
#     ft_strrchr.o ft_strncmp.o ft_memchr.o ft_memcmp.o ft_strnstr.o \
#     ft_atoi.o ft_calloc.o ft_strdup.o ft_substr.o ft_strjoin.o ft_strtrim.o ft_split.o \
# 	ft_itoa.o ft_strmapi.o ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o \
# 	ft_putendl_fd.o ft_putnbr_fd.o \


# BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
# 	ft_lstclear.c ft_lstiter.c ft_lstmap.c \

# BONUS_OBJ = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o ft_lstdelone.o \
# 	ft_lstclear.o ft_lstiter.o ft_lstmap.o \

# OBJ = $(SRC:%.c=%.o)

# all: $(NAME)

# $(NAME): $(OBJ)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@ 
# 	ar rc $(NAME) $@

# bonus: $(BONUS_OBJ)

# $(BONUS_OBJ): $(BONUS_SRC)
# 	$(CC) $(CFLAGS) -c $(BONUS_SRC)
# 	ar rc $(NAME) $(BONUS_OBJ)

# norm:
# 	norminette $(SRC) 

# clean: 
# 	rm -f $(OBJ) $(BONUS_OBJ)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# so:
# 	gcc -nostartfiles -fPIC $(CFLAGS) $(SRC) $(BONUS_SRC)
# 	gcc -nostartfiles -shared -o libft.so $(OBJ) $(BONUS_OBJ)

# .PHONY: all clean fclean re bonus