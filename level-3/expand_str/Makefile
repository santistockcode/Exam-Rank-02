CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = expand_str

all: $(NAME)

${NAME} : expand_str.c
	${CC} ${FLAGS} expand_str.c -o ${NAME}


testkos : ${NAME}
	./${NAME} ""  | cat -e
	./${NAME} "hola" "tu" | cat -e
	./${NAME} | cat -e


testoks : ${NAME}
	./${NAME} "hola"  | cat -e
	./${NAME} "hola tu          " | cat -e
	./${NAME} "See? It's easy to print the same thing" | cat -e
	./${NAME} " this        time it      will     be    more complex  " | cat -e
