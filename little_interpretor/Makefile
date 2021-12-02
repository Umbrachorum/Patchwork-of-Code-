##
## EPITECH PROJECT, 2021
## B-OOP-400-BDX-4-1-tekspice-william.sautour
## File description:
## Makefile
##

NAME	=	abstractVM

CXXFLAGS 	= 	-I./include -I./../../include

CC	= g++

CXXFLAGS 	+= 	-W -Wall -Wextra

SRC		=	src/BigDecimal.cpp	\
			src/Core.cpp		\
			src/Double.cpp		\
			src/Exceptions.cpp	\
			src/Factory.cpp		\
			src/Float.cpp		\
			src/Int8.cpp		\
			src/Int16.cpp		\
			src/Int32.cpp		\
			src/Parser.cpp		\
			src/Stack.cpp		\
			src/is_empty.cpp	\
			src/roundOperand.cpp	\
			src/main.cpp

OBJ		=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		 $(CC) $(OBJ) -o $(NAME) $(CXXFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
