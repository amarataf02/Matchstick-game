##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile of infinadd
##

NAME	=	matchstick

SRC	=	src/main.c			\
		src/start_game.c	\
		src/print_map.c		\
		src/calc_ai.c		\
		src/checkers.c		\
		src/getlines.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include/ -pedantic -lncurses -g3 # -Wpedantic -Wno-long-long -Werror -W -Wall -Wextra

LDLIBS	=	-L./lib/ -lmy

all:		$(NAME)

$(NAME):	make_lib $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDLIBS)

make_lib:
		$(MAKE) -C lib/my

clean:
		rm -f $(OBJ)
		$(MAKE) clean -C lib/my/

fclean: 	clean
		rm -f $(NAME)
		$(MAKE) fclean -C lib/my

run_tests:

re:		fclean all
		$(MAKE) re -C lib/my
