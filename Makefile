NAME-S	=	server
NAME-C	=	client

SRC-S = ./serv_src/server.c ./serv_src/minitalk_utils.c
SRC-C = ./cl_src/client.c ./cl_src/minitalk_utils.c

OBJ-S	=	${SRC-S:%.c=%.o}
OBJ-C	=	${SRC-C:%.c=%.o}

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

.PHONY:		all clean fclean re

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME-C} ${NAME-S}

${NAME-S}:	${OBJ-S}
			@${CC} ${CFLAGS} ${OBJ-S} -o ${NAME-S}

${NAME-C}:	${OBJ-C}
			@${CC} ${CFLAGS} ${OBJ-C} -o ${NAME-C}
clean:
			${RM} ${OBJ-S}
			${RM} ${OBJ-C}

fclean:		clean
			${RM} ${NAME-S} ${NAME-C}

re:			fclean all
