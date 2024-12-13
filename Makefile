CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
NAME		=	minishell
INCLUDES	=	./includes

SOURCES		= 	minishell.c
OBJS		=	$(SOURCES:.c=.o)	\
				$(EXEC_OBJ)	\
				$(PARSE_OBJ)	\
				$(UTILS_OBJ)

UTILS_DIR	=	./utils
UTILS_SRC	=	ms_utils.c	\
				ms_mem_free.c
UTILS_OBJ	=	$(addprefix $(UTILS_DIR)/, $(UTILS_SRC:.c=.o))

EXEC_DIR	=	./execute
EXEC_SRC	=	ms_script_loop.c
# ms_execute_cmd.c	
EXEC_OBJ	=	$(addprefix $(EXEC_DIR)/, $(EXEC_SRC:.c=.o))

PARSE_DIR	=	./parse
PARSE_SRC	=	ms_init_cmd.c	\
				ms_make_list.c	\
				ms_parse_path.c	\
				ms_open_fd.c	\
				check_redirection_target.c	\
				check_redirection_sign.c
PARSE_OBJ	=	$(addprefix $(PARSE_DIR)/, $(PARSE_SRC:.c=.o))

LIBFTDIR	=	./libft
LIBFT		=	$(LIBFTDIR)/libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -lreadline

%.o : %.c
	$(CC) $(CFLAGS) -I$(LIBFTDIR) -I$(INCLUDES) -o $@ -c $<

$(LIBFT) :
	@make -C $(LIBFTDIR) all

clean :
	rm -f $(OBJS)
	@make -C $(LIBFTDIR) clean

fclean : clean
	rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re : fclean all

.PHONY : all clean fclean re