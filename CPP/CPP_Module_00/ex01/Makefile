#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM		=	rm -rf

# Dir and file names
NAME	=	
SRCS	=	
OBJS	=	$(SRCS:.cpp=.o)

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# Compiles sources into objects
.cpp.o: $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@

# Removes objects
clean:
	$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all

.PHONY: all bonus clean fclean re