##
## EPITECH PROJECT, 2021
## B-CNA-410-4-1-groundhog-geoffroy.yann@epitech.eu
## File description:
## Makefile
##

CC = g++ -g3

RM = rm -f

CXXFLAGS	=	-W -Wall -Wextra -I./include

SRC			=	src/trade.cpp	\
				src/init.cpp	\
				src/main.cpp

OBJ			=	$(SRC:.cpp=.o)

NAME		=		trade

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: re all clean fclean
