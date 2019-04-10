##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makfile Lem-in
##

SRC_SOL = 	solver_folder/main.c	\
			solver_folder/init.c	\
			solver_folder/algo.c	\
			solver_folder/detect.c

CFLAGS = -g -Iinclude

OBJ_SOL = $(SRC_SOL:.c=.o)

O_SOL = solver_folder/*.o

NAME_SOL = solver

NAME_GEN = generator

GCCWAY = gcc -o

all: $(NAME_SOL)

$(NAME_SOL): $(OBJ_SOL)
	$(GCCWAY) $(NAME_SOL) $(OBJ_SOL)

clean:
	rm -f $(O_SOL)

fclean: clean
	rm -f $(NAME_SOL)

re: fclean all

.PHONY: all clean fclean re
