CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = minishell

SOURCES = 	minishell.c	\
			ms_utils.c	\
			ms_init_cmd.c	\
			ms_mem_free.c	\
			ms_make_list.c	\
			ms_parse_path.c	\
			check_redirection_sign_2.c	\
			check_redirection_sign_1.c

OBJS = $(SOURCES:.c=.o)

LIBFT = $(LIBFTDIR)/libft.a
LIBFTDIR = ./libft

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -lreadline

%.o : %.c
	$(CC) $(CFLAGS) -I$(LIBFTDIR) -o $@ -c $<

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