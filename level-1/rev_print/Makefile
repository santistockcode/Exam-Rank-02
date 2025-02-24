
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = rev_print

all: $(NAME)

test: $(NAME)
	./$(NAME) "zaz" | cat -e
	./$(NAME) "dub0 a POIL" | cat -e
	./$(NAME) | cat -e

$(NAME): rev_print.c
	$(CC) $(CFLAGS) -o $(NAME) rev_print_own.c

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re