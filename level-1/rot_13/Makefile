CC = cc
CFLAGS = -Well -Werror -Wextra
NAME = rot_13

all: $(NAME)

$(NAME): $(NAME).c
	$(CC) $(CFLAGS) -o $(NAME) $(NAME).c

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re