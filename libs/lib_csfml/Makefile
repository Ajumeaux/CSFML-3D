##
## EPITECH PROJECT, 2020
## libmy_csfml
## File description:
## Makefile
##

SRC		=	button_adm.c	\
			button_use.c	\
			screen_pixel.c

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy_csfml.a

.H		=	my_csfml.h

all:	compile move

compile:	$(OBJ)
	ar r $(NAME) $(OBJ)

move:
	@mv $(NAME) ../
	@cp $(.H) ../

clean:
	@rm -rf $(OBJ)

fclean:	clean
	@rm -rf ../$(NAME)
	@rm -rf ../$(.H)

re:	fclean all