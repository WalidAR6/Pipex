NAME = libftprintf.a

AR = ar -crs

FLAGS = -Wall -Wextra -Werror

CC = cc

SRC = 		   ft_putchar.c\
				ft_putnbr.c\
				ft_putstr.c\
 	 ft_putnbr_base_upper.c\
	 ft_putnbr_base_lower.c\
	   ft_putnbr_unsigned.c\
		   ft_putnbr_base.c\
		   		ft_printf.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${AR} ${NAME} ${OBJ}

%.o: %.c ../../inc/ft_printf.h
	${CC} ${FLAGS} -c $<

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all