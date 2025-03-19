CC = cc
CFLAGS = -Werror -Wextra -Wall
NAME = inter

all: ${NAME}

test: ${NAME}
	./${NAME} "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
	./${NAME} ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
	./${NAME} "rien" "cette phrase ne cache rien" | cat -e

${NAME} : inter.c
	cc -Wall -Wextra -Werror inter.c -o ${NAME}

clean: 
	rm ${NAME}

.phony: all clean