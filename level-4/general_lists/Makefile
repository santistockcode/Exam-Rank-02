CC = cc
FLAGS = -Wall -Wextra -Werror -g
NAME = lists

all: $(NAME)

${NAME} : lists.h general.c
	${CC} ${FLAGS} general.c -o ${NAME}

clean: lists
	rm lists

re: 
	clean 
	all