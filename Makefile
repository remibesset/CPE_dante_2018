##
## EPITECH PROJECT, 2019
## makefile globae
## File description:
## makefile
##

all:
	$(MAKE) -C generateur
	$(MAKE) -C solveur

clean:
	$(MAKE) clean -C generateur
	$(MAKE) clean -C solveur

fclean:
	$(MAKE) fclean -C generateur
	$(MAKE) fclean -C solveur

re:
	$(MAKE) re -C generateur
	$(MAKE) re -C solveur

.PHONY: all clean fclean re