NAME = pipex 

FLAGS = -Wall -Wextra -Werror

SRC = main_bonus\
		here_doc

OBJ_DIR = ../../bin/bonus/

OBJ = ${SRC:=.o}

OBJCTS = ${addprefix $(OBJ_DIR),$(OBJ)}

EXE = ../libft_global/libft.a

all: ${NAME}

${NAME} : ${OBJCTS} 
	${CC} ${FLAGS} $(EXE) $^ -o $@

$(OBJ_DIR)%.o : %.c ../../inc/pipex_bonus.h
	@mkdir -p $(OBJ_DIR)
	${CC} ${FLAGS} -c $< -o $@ -g

clean: 
	@${RM} $(OBJCTS)

fclean : clean
	@${RM} -rf ${NAME} $(OBJ_DIR)

re: fclean all