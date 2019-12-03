##
## EPITECH PROJECT, 2017
## n4s
## File description:
## Makefile
##

SRC		=	src/main.c		\
			src/car_movement.c	\
			src/get_info.c		\
			src/my_put.c		\
			src/check.c		\
			src/options.c		\
			src/simulation.c	\
			src/str_to_array.c	\
			src/wheels_dir.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -Wextra

CC		=	gcc

NAME		=	ai

all:		$(NAME) clean

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all
