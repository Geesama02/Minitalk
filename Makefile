CFLAGS = -Wall -Wextra -Werror
CC = cc
NAME = client
SRC = ft_printf_mem.c ft_lower_hex.c ft_putchar.c ft_putnbr.c ft_isdigit.c \
	 ft_putstr.c ft_upper_hex.c u_printf.c ft_printf.c ft_atoi.c
OBJS = ${SRC:.c=.o}
CLIENT = client.c
SERVER = server.c
CLIENT_BONUS = client_bonus.c
SERVER_BONUS = server_bonus.c
CLIENT_OBJS = ${CLIENT:.c=.o}
SERVER_OBJS = ${SERVER:.c=.o}
CLIENT_BONUS_OBJS = ${CLIENT_BONUS:.c=.o}
SERVER_BONUS_OBJS = ${SERVER_BONUS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS} ${CLIENT_OBJS} ${SERVER_OBJS}
	${CC} ${CFLAGS} ${OBJS} ${CLIENT_OBJS} -o ${NAME}
	${CC} ${CFLAGS} ${OBJS} ${SERVER_OBJS} -o server

%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

clean : 
	rm -rf ${OBJS} ${CLIENT_OBJS} ${SERVER_OBJS} ${CLIENT_BONUS_OBJS} ${SERVER_BONUS_OBJS}

fclean : clean
	rm -rf ${NAME} server

re : fclean all

bonus : ${OBJS} ${CLIENT_BONUS_OBJS} ${SERVER_BONUS_OBJS}
	${CC} ${CFLAGS} ${OBJS} ${CLIENT_BONUS_OBJS} -o ${NAME}
	${CC} ${CFLAGS} ${OBJS} ${SERVER_BONUS_OBJS} -o server

.PHONY : all clean fclean re bonus