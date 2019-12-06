##
## EPITECH PROJECT, 2019
## 103cipher_2019
## File description:
## Project makefile template
##

DSRC =	./src/

SRC	=	$(DSRC)main.c		\
		$(DSRC)matrix.c		\
		$(DSRC)encode.c		\
		$(DSRC)decode.c		\
		$(DSRC)prepare.c	\
		$(DSRC)display.c	\
		$(DSRC)103cipher.c

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
