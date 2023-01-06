LIBFT_DIR = src/libft_global

MANDA_DIR = src/mandatory

OBJ_DIR = bin/

all: 
	@${MAKE} -C ${LIBFT_DIR}
	@echo "\033[92mlibft compiled ✔\033[0m"
	@${MAKE} -C ${MANDA_DIR}
	@echo "\033[92mmandatory compiled ✔\033[0m"

clean:
	@${MAKE} -C ${MANDA_DIR} clean
	@${MAKE} -C ${LIBFT_DIR} clean

fclean:
	@${MAKE} -C ${LIBFT_DIR} fclean
	@${MAKE} -C ${MANDA_DIR} fclean
	@$(RM) -rf $(OBJ_DIR)

re: fclean all


























# NAME = pipex

# CC = cc

# FLAGS = -Wall -Wextra -Werror

# LIB_G = src/ft_printf/libft.a

# PRINTF_P = src/ft_printf

# PRINTF_H = inc/ft_printf.h

# FILES = main\
# 		src/parsing/check_args\
# 		src/errors/first_arg_er


# OBJ = $(FILES:=.o);

# all: ${NAME} ${PRINTF}

# ${PRINTF}: ${PRINTF_H}
# 	@${MAKE} -C ${PRINTF_P}
# 	@echo "\033[92mft_printf compiled ✔\033[0m"

# ${NAME} : $(PRINTF) $(OBJ)
# 	${CC} $^ -o $@ 

# %.o : %.c 
# 	${CC} ${FLAGS} -c $< -o $@

# clean: 
# 	@${RM} *.o */*.o */*/*.o

# fclean: 
# 	@${RM} *.o */*.o */*/*.o */*/*.a ${NAME}

# re: clean fclean all