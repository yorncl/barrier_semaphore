CC = gcc
CFLAGS = -Wall -Wextra -Werror


LDFLAGS = -pthread
RM = rm -rf

SRC= $(wildcard ./*.c)
OBJ=$(SRC:%.c=%.o)

NAME=barrier

all : $(NAME)

debug: CFLAGS += -fsanitize=address -g
debug: all 


$(NAME):  $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
