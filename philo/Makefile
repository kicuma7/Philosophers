NAME = philo

CC = cc

CFLAGS = -I utls/include -Wall -Wextra -Werror 

SRCS = 	src/main.c 	\
		src/validation.c \
		src/init.c \
		src/simulation.c \
		src/pick_up_forks.c \
		src/error.c \
		src/time.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

