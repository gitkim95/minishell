CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = minishell

SOURCES = 	minishell.c	\
			check_redirection_sign.c	\
			ms_utils.c	
OBJS = $(SOURCES:.c=.o)

LIBFT = $(LIBFTDIR)/libft.a
LIBFTDIR = ./libft

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -lreadline

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

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