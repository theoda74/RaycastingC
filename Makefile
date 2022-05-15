##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## A simple Makefile
##

FLAG	=	-lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -lm

SRC	=	src/main.c		\
		src/event_handler.c	\
		src/draw.c		\
		src/destroy.c		\
		src/loop.c		\
		src/rays_walls.c	\
		utils/create_rec.c 	\
		utils/create_spr.c 	\
		utils/create_txt.c 	\
		utils/create_win.c

OBJ	=	$(SRC:.c=.o)

NAME	=	raycasting

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(FLAG)
	echo -e "\033[1;32mCompilation Completed!\033[0m";

clean:
	$(RM) src/*.o
	$(RM) utils/*.o
	echo -e "\033[1;32mRepository Cleared!\033[0m";
fclean:
	$(RM) src/*.o
	$(RM) utils/*.o
	$(RM) $(NAME)
	echo -e "\033[1;32mRepository Cleared!\033[0m";

re: fclean all
