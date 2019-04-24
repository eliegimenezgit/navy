##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## file of compilation
##

SRC = ./src/main.c	      \
      ./src/game.c	      \
      ./src/your_turn.c	      \
      ./src/map.c             \
      ./src/your_turn2.c      \
      ./src/open_path.c       \
      ./src/other_turn.c      \
      ./src/connection.c      \
      ./src/good_size_boat.c  \
      ./my_put/my_putchar.c	\
      ./my_put/my_put_nbr.c	\
      ./my_put/my_putstr.c	\
      ./my_put/my_strlen.c	\
      ./my_put/my_getnbr.c

OBJ = $(SRC:.c=.o)

NAME = navy

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -I.

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
