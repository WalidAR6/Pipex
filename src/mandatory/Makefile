NAME = pipex

NAME_P = $(PWD)/$(NAME)

FLAGS = -Wall -Wextra -Werror

SRC = main check_args

OBJ_DIR = ../../bin/mandatory/

OBJ = ${SRC:=.o}

OBJCTS = ${addprefix $(OBJ_DIR),$(OBJ)}

EXE = ../libft_global/libft.a

all: ${NAME}

${NAME} : ${OBJCTS} 
	@${CC} ${FLAGS} $(EXE) $^ -o $@
	@mv $(NAME) $(NAME_P)

$(OBJ_DIR)%.o : %.c ../../inc/pipex.h
	@mkdir -p $(OBJ_DIR)
	@${CC} ${FLAGS} -c $< -o $@

clean: 
	@${RM} $(OBJCTS)

fclean : clean
	@${RM} -rf ${NAME_P} $(OBJ_DIR)

re: fclean all