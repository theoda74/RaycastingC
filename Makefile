##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## A simple Makefile
##

FLAG	=	-lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -lm

SRC		=	src/main.c			\
			src/event_handler.c	\
			src/draw.c			\
			src/destroy.c		\
			src/loop.c			\
			utils/create_rec.c 	\
			utils/create_spr.c 	\
			utils/create_txt.c 	\
			utils/create_win.c

OBJ		=	$(SRC:.c=.o)

NAME	=	raycasting

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(FLAG)

clean:
	$(RM) src/*.o
	$(RM) utils/*.o

fclean: clean
	$(RM) $(NAME)

re: fclean all