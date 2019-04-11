##
## EPITECH PROJECT, 2019
## makefile globae
## File description:
## makefile
##

NAME = see_below

SOL_PATH = solver/

GEN_PATH = generator/

all:	$(NAME)

$(NAME):
	$(MAKE) -C $(GEN_PATH)
	$(MAKE) -C $(SOL_PATH)

clean:
	$(MAKE) clean -C $(GEN_PATH)
	$(MAKE) clean -C $(SOL_PATH)

fclean:
	$(MAKE) fclean -C $(GEN_PATH)
	$(MAKE) fclean -C $(SOL_PATH)

re: fclean all

.PHONY: all clean fclean re