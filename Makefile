CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src
OBJ_DIR = obj
LDFLAGS = -lpthread
INCLUDE = -Iinclude

SRCS = ${SRC_DIR}/philo.c ${SRC_DIR}/validate_args.c ${SRC_DIR}/init_table.c \
	   ${SRC_DIR}/dinner.c ${SRC_DIR}/number_utils.c

OBJS = ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

NAME = philo

all: ${NAME}

$(NAME): ${OBJS}
	$(CC) ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

clean:
	rm -rf ${OBJ_DIR}

fclean: clean
	rm -rf ${NAME}

re: fclean all
