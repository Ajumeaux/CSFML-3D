##
## EPITECH PROJECT, 2021
## libmy_base
## File description:
## Makefile
##

SRC		=	array1.c	\
			array2.c	\
			errors.c	\
			math1.c	\
			nbr_tests.c	\
			prints1.c	\
			str_comps.c	\
			str_manip2.c	\
			str_manip1.c	\
			str_to_array.c	\
			sys1.c	\

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy_base.a

.H		=	my_base.h

all:	compile move

compile:	$(OBJ)
	@ar r $(NAME) $(OBJ)

move:
	@mv $(NAME) ../
	@cp $(.H) ../

clean:
	@rm -rf $(OBJ)

fclean:	clean
	@rm -rf ../$(NAME)
	@rm -rf ../$(.H)

re:	fclean all