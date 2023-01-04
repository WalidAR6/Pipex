NAME = pipex

CC = cc

FLAGS = -Wall -Wextra -Werror

PRINTF = src/ft_printf/libftprintf.a

PRINTF_P = src/ft_printf

PRINTF_H = inc/ft_printf.h

FILES = main\
		src/parsing/check_args\
		src/errors/first_arg_er


OBJ = $(FILES:=.o);

all: ${NAME} ${PRINTF}

${PRINTF}: ${PRINTF_H}
	@${MAKE} -C ${PRINTF_P}
	@echo "\033[92mft_printf compiled ✔\033[0m"

${NAME} : $(PRINTF) $(OBJ)
	${CC} $^ -o $@ 

%.o : %.c 
	${CC} ${FLAGS} -c $< -o $@

clean: 
	@${RM} *.o */*.o */*/*.o

fclean: 
	@${RM} *.o */*.o */*/*.o */*/*.a ${NAME}

re: clean fclean all