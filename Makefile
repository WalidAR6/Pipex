NAME = pipex

CC = cc

FLAGS = -Wall -Wextra -Werror

PRINTF = src/ft_printf/libftprintf.a

PRINTF_P = src/ft_printf

PRINTF_H = inc/ft_printf.h

FILES = main

OBJ = $(FILES:=.o);

all: ${NAME}

${PRINTF}: ${PRINTF_H}
	${MAKE} -C ${PRINTF_P}

${NAME} : $(PRINTF) $(OBJ)
	${CC} $^ -o $@ 

%.o : %.c 
	${CC} ${FLAGS} -c $< -o $@ -g

clean: 
	@${RM} *.o */*.o */*/*.o

fclean: 
	@${RM} *.o */*.o */*/*.o */*/*.a ${NAME}

re: clean fclean all