NAME = btc

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -f

SRCS = main.cpp \
		BitcoinExchange.cpp
		
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re