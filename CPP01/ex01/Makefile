NAME = zombie

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=address

RM = rm -f

SRCS = main.cpp \
		zombieHorde.cpp \
		Zombie.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re