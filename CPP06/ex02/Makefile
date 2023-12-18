NAME = app

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -f

SRCS = main.cpp \
		Base.cpp \
		A.cpp \
		B.cpp \
		C.cpp
		
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re