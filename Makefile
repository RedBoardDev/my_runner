##
## EPITECH PROJECT, 2021
## Graphical
## File description:
## Makefile
##

SRC	=	src/my_runner.c	\
		src/utils/draw_utils.c	\
		src/utils/utils_csfml.c	\
		src/events.c	\
		src/main.c	\
		src/inits_obj.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

CC	=	gcc -g

CSFML_FLAGS	=	-lcsfml-graphics    \
			-lcsfml-window    \
			-lcsfml-system    \
			-lcsfml-audio	\
			-lm

LIB	=	-I./include -L./lib -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CSFML_FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all clean