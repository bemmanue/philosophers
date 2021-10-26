
NAME			=	philo

SRCS			=	philo.c	\
					utils.c	\
					forks.c	\
					eat.c	\
					init.c

OBJS			=	$(SRCS:.c=.o)
DEPS 			= 	$(SRCS:.c=.d)

HEAD			=	philo.h

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -MMD

all:				$(NAME)

.c.o:
					$(CC) $(CFLAGS) -Iincludes/ -c $< -o $@

$(NAME):			$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
					rm -rf $(OBJS) $(DEPS)

fclean:				clean
					rm -rf $(NAME)

re:					fclean all
.PHONY:				all clean fclean re
-include			$(OBJS:.o=.d)
