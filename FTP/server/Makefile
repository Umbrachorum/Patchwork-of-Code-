NAME	=	myftp

CC	=	gcc

RM	=	rm -f

SRCS	=	src/server.c		\
			src/schema.c		\
			commands/cpuda.c	\
			commands/cwd.c		\
			commands/dele.c		\
			commands/help.c		\
			commands/list.c		\
			commands/noop.c		\
			commands/pass.c		\
			commands/port.c		\
			commands/pwd.c		\
			commands/quit.c		\
			commands/retr.c		\
			commands/stor.c		\
			commands/user.c		\
			commands/pasv.c		\
			main.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-I ./include/
CFLAGS	+=	-Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o ../$(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS) ../$(NAME)

fclean: clean
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re