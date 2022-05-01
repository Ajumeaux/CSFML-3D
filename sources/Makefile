##
## EPITECH PROJECT, 2021
## my_rpg
## File description:
## Makefile sources
##

SRC		=	main.c	\
			matrix_calcs.c	\
			matrix_defs1.c	\
			matrix_defs2.c	\
			meshes.c	\
			my_strtok.c	\
			obj_file_handling.c	\
			vectors_less_simple.c	\
			vectors_simple.c	\
			sprite_creation.c	\

OBJ		=	$(SRC:.c=.o)

NAME	=	cubed

LIBPTH	=	../libs

INCL	=	../include

CFLAGS	=	-I$(INCL) -I$(LIBPTH) -L$(LIBPTH) -lm -lmy_base -lmy_csfml -lcsfml-system -lcsfml-window -lcsfml-graphics -W -Wall -Wextra

DEBUGOPT	=	-g

all:	compile move

compile:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

debug:
	gcc -o $(NAME) $(SRC) $(CFLAGS) $(DEBUGOPT)
	@mv $(NAME) ../

move:
	@mv $(NAME) ../

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(addprefix ../,$(NAME))

re:		fclean all
