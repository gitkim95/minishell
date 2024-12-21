CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
NAME		=	minishell
INCLUDES	=	./includes

OBJS_DIR	=	./obj
OBJS		=	$(SOURCES_OBJ)	\
				$(EXEC_OBJ)	\
				$(PARSE_OBJ)	\
				$(UTILS_OBJ)	\
				$(BUILTIN_OBJ)	\
				$(ENV_OBJ)		\
				$(HASH_OBJ)		\
				$(SIGNAL_OBJ)

SOURCES		= 	minishell.c
SOURCES_OBJ =	$(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))

BUILTIN_DIR	=	./builtin
BUILTIN_SRC =	ms_builtin_cd.c		ms_builtin_echo.c	ms_builtin_env.c	\
				ms_builtin_export.c	ms_builtin_pwd.c	ms_builtin_unset.c	\
				ms_builtin.c
BUILTIN_OBJ	=	$(addprefix $(OBJS_DIR)/, $(BUILTIN_SRC:.c=.o))

ENV_DIR 	=	./env
ENV_SRC 	=	ms_env.c	ms_env_utils.c
ENV_OBJ 	=	$(addprefix $(OBJS_DIR)/, $(ENV_SRC:.c=.o))

HASH_DIR	=	./hash
HASH_SRC	=	ft_hash.c	ft_hash_utils.c
HASH_OBJ	=	$(addprefix $(OBJS_DIR)/, $(HASH_SRC:.c=.o))

UTILS_DIR	=	./utils
UTILS_SRC	=	ms_utils.c	\
				ms_mem_free.c
UTILS_OBJ	=	$(addprefix $(OBJS_DIR)/, $(UTILS_SRC:.c=.o))

EXEC_DIR	=	./execute
EXEC_SRC	=	ms_execute_logic.c	\
				ms_close_fd.c	\
				ms_execute_cmd.c	\
				ms_processing.c	\
				ms_init_var.c	\
				ms_script_loop.c	\
				ms_set_pipe.c	\
				ms_handle_heredoc.c
EXEC_OBJ	=	$(addprefix $(OBJS_DIR)/, $(EXEC_SRC:.c=.o))

PARSE_DIR	=	./parse
PARSE_SRC	=	ms_init_cmd.c	\
				ms_make_list.c	\
				ms_parse_path.c	\
				ms_open_fd.c	\
				check_redirection_target.c	\
				check_redirection_sign.c	\
				handle_env_sign.c	\
				handle_quote_mark.c	\
				handle_quote_utils.c
PARSE_OBJ	=	$(addprefix $(OBJS_DIR)/, $(PARSE_SRC:.c=.o))

SIGNAL_DIR	=	./signal
SIGNAL_SRC	=	ms_signal.c	ms_signal_heredoc.c
SIGNAL_OBJ	=	$(addprefix $(OBJS_DIR)/, $(SIGNAL_SRC:.c=.o))

LIBFTDIR	=	./libft
LIBFT		=	$(LIBFTDIR)/libft.a

vpath %.c	$(BUILTIN_DIR)	$(ENV_DIR)		$(HASH_DIR)		$(UTILS_DIR)	\
			$(EXEC_DIR)		$(PARSE_DIR)	$(SIGNAL_DIR)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -lreadline

$(OBJS_DIR)/%.o : %.c
	@mkdir -p $(OBJS_DIR)
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