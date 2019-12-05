##
## EPITECH PROJECT, 2019
## 103cipher_2019
## File description:
## Project makefile template
##

SRC	=	main.c		\
		matrix.c	\
		chiffre.c	\
		prepare.c	\
		display.c	\
		103cipher.c

OBJ	=	$(SRC:.c=.o)

NAME	=	103cipher

CFLAGS	+= -Wall -Wextra -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lm

clean:
	rm -f  $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

#tests_run:

.PHONY :        clean fclean re
