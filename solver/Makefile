##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makfile Lem-in
##

SRC_SOL = 	main.c	\
			init.c	\
			algo.c	\
			detect.c

CFLAGS = -g

OBJ_SOL = $(SRC_SOL:.c=.o)

O_SOL = *.o

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
