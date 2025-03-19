CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = ulstr


all: $(NAME)

test: $(NAME)

	./$(NAME) "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification." | cat -e > output1
	diff output1 expected1
	./$(NAME) "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  " | cat -e > output2
	diff output2 expected2
	./$(NAME) "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot" | cat -e > output3
	diff output3 expected3
	./$(NAME) | cat -e > output4
	diff output4 expected4


$(NAME): $(NAME).c
	$(CC) $(CFLAGS) -o $(NAME) $(NAME).c

clean: 
	rm -f $(NAME)
	rm output1 output2 output3 output4

.phony: all clean