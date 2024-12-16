CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
NAME		=	minishell
INCLUDES	=	./includes

SOURCES		= 	minishell.c
OBJS		=	$(SOURCES:.c=.o)	\
				$(EXEC_OBJ)	\
				$(PARSE_OBJ)	\
				$(UTILS_OBJ)	\
				$(BUILTIN_OBJ)	\
				$(ENV_OBJ)		\
				$(HASH_OBJ)		\
				$(SIGNAL_OBJ)

BUILTIN_DIR	=	./builtin
BUILTIN_SRC =	ms_builtin_cd.c		ms_builtin_echo.c	ms_builtin_env.c	\
				ms_builtin_export.c	ms_builtin_pwd.c	ms_builtin_unset.c	\
				ms_builtin.c
BUILTIN_OBJ	=	$(addprefix $(BUILTIN_DIR)/, $(BUILTIN_SRC:.c=.o))

ENV_DIR 	=	./env
ENV_SRC 	=	ms_env.c	ms_env_utils.c
ENV_OBJ 	=	$(addprefix $(ENV_DIR)/, $(ENV_SRC:.c=.o))

HASH_DIR	=	./hash
HASH_SRC	=	ft_hash.c	ft_hash_utils.c
HASH_OBJ	=	$(addprefix $(HASH_DIR)/, $(HASH_SRC:.c=.o))

UTILS_DIR	=	./utils
UTILS_SRC	=	ms_utils.c	\
				ms_mem_free.c
UTILS_OBJ	=	$(addprefix $(UTILS_DIR)/, $(UTILS_SRC:.c=.o))

EXEC_DIR	=	./execute
EXEC_SRC	=	ms_execute_logic.c	\
				ms_close_fd.c	\
				ms_execute_cmd.c	\
				ms_processing.c	\
				ms_init_var.c	\
				ms_script_loop.c	\
				ms_set_pipe.c	\
				ms_handle_heredoc.c
EXEC_OBJ	=	$(addprefix $(EXEC_DIR)/, $(EXEC_SRC:.c=.o))

PARSE_DIR	=	./parse
PARSE_SRC	=	ms_init_cmd.c	\
				ms_make_list.c	\
				ms_parse_path.c	\
				ms_open_fd.c	\
				check_redirection_target.c	\
				check_redirection_sign.c
PARSE_OBJ	=	$(addprefix $(PARSE_DIR)/, $(PARSE_SRC:.c=.o))

SIGNAL_DIR	=	./signal
SIGNAL_SRC	=	ms_signal.c
SIGNAL_OBJ	=	$(addprefix $(SIGNAL_DIR)/, $(SIGNAL_SRC:.c=.o))

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