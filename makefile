SRCS		= get_next_line.c \ get_next_line_utils.c

OBJ			= ${SRCS: .c=.o}

NAME 		= get.a

CC 			= gcc
CFLAGS		= -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJ}
		ar crs $@ $^

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

clean:
		rm -rf ${OBJ}
	
fclean: clean
		rm -rf ${NAME}

re: fclean all


.PHONY: all clean fclean re 
