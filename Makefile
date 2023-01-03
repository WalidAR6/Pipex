NAME = pipex

CC = cc

FLAGS = -Wall -Wextra -Werror

PRINTF = ft_printf/libftprintf.a

PRINTF_P = ft_printf

PRINTF_H = inc/ft_printf.h

FILES = main
OBJ = $(FILES:=.o);
P_OBJ = ${PRINTF_SRC:.c=.o}

all: ${NAME}

${PRINTF}: ${PRINTF_H}
	${MAKE} -C ${PRINTF_P}

${NAME} : $(PRINTF) $(OBJ)
	${CC} $^ -o $@ 

%.o : %.c 
	${CC} ${FLAGS} -c $< -o $@ 

clean: 
	${RM} *.o */*.o */*/*.o

fclean: 
	 ${RM} *.o */*.o */*/*.o */*.a ${NAME} 

