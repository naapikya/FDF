NAME = fdf.a
SRCS = $(shell find "." -maxdepth 1 -name '*.c' ! -name "_bonus.c")
BONUS = $(shell find "." -maxdepth 1 -name '*.c' ! -name "key_hooks.c")
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${BONUS:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
FRAMEWORK = -framework OpenGL -framework AppKit
INCLUDES = minilibx_macos/libmlx.a
AR = ar csr

.c.o :
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
	
		make -C minilibx_macos/ all
		${AR} ${NAME} ${OBJS}
		${CC} ${CFLAGS} $(NAME) ${INCLUDES} ${FRAMEWORK} -o fdf

bonus: ${OBJS_BONUS} 
		${RM} ${NAME}
		${RM} fdf
		make -C minilibx_macos/ all
		${AR} ${NAME} ${OBJS_BONUS}
		${CC} ${CFLAGS} $(NAME) ${INCLUDES} ${FRAMEWORK} -o fdf
	
all : ${NAME}

clean : 
		
		${RM} ${OBJS} ${OBJS_BONUS}}
		make -C minilibx_macos/ clean

fclean : clean
		
		${RM} ${NAME}
		${RM} fdf

re : fclean all



.PHONY: all clean fclean bonus re .c.o