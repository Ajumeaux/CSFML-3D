##
## EPITECH PROJECT, 2021
## my_rpg
## File description:
## Makefile
##

PROJ	=	./sources

TEST	=	./tests

LIBPTH1	=	./libs/lib_base

LIBPTH2	=	./libs/lib_csfml

all:	compile

compile:	compilib
	make -C $(PROJ)

debug:	compilib
	make debug -C $(PROJ)

compilib:
	make -C $(LIBPTH1)
	make -C $(LIBPTH2)

tests_run:	compilib
	make -C $(TEST)

clean:
	@make clean -C $(LIBPTH1)
	@make clean -C $(LIBPTH2)
	@make clean -C $(PROJ)
	@make clean -C $(TEST)

fclean:	clean
	@make fclean -C $(LIBPTH1)
	@make fclean -C $(LIBPTH2)
	@make fclean -C $(PROJ)
	@make fclean -C $(TEST)
	@rm -f vgcore*

re: fclean all