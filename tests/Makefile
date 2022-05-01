##
## EPITECH PROJECT, 2021
## my_rpg
## File description:
## Makefile tests
##

SRC		=	matrix_calcs.c	\
			matrix_defs1.c	\
			matrix_defs2.c	\
			meshes.c	\
			obj_file_handling.c	\
			vectors_less_simple.c	\
			vectors_simple.c	\

TEST	=	tests_vectors1.c	\

OBJ		=	$(SRC:.c=.o)

OBJT	=	$(TEST:.c=.o)

TNAME	=	tests_

LIB		=	../libs

INCL	=	../include

CFLAGS	=	-I$(INCL) -I$(LIB) -L$(LIB) -lm -lmy_base -lmy_csfml -lcsfml-system -lcsfml-window -lcsfml-graphics -lcriterion --coverage -W -Wall -Wextra

all:	tests_run

tests_run:	compile_test clean
	@./$(TNAME)

compile_test:	fclean
	gcc -o $(TNAME) $(addprefix ../sources/, $(SRC)) $(TEST) $(CFLAGS)

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJT)
	@rm -f vgcore*

fclean:	clean
	@rm -f $(TNAME)
	@rm -f *.gcno
	@rm -f *.gcda

re:	fclean all