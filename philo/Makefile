SRCS = death.c dinner.c free.c list.c main.c solo.c utils.c
NAME = philo
CC = cc
CFLGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
RM = rm -f

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLGS) -c $^ -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 