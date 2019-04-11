##
## EPITECH PROJECT, 2019
## Makefile generator
## File description:
## generator
##

SRC = src/main.c \
	src/utils.c \
	src/verif.c \
	src/create_map.c \
	src/back_tracking.c \
	src/back_tracking2.c \
	src/finish_imperfection.c \
	src/second_algo.c \

CFLAGS = -g -Iinclude

OBJ = $(SRC:.c=.o)

NAME = generator

GCCWAY = gcc -o

all: $(NAME)

$(NAME): $(OBJ)
	$(GCCWAY) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
