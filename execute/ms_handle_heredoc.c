/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_handle_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:15:16 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/21 13:14:09 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "ms_execute.h"
#include "ms_signal.h"
#include "ms_utils.h"
#include "libft.h"

static char	*append_input(char *prev, char *new)
{
	char	*input;

	input = ft_calloc(ft_strlen(prev) + ft_strlen(new) + 2, sizeof(char));
	if (!input)
		return (NULL);
	ft_strcat(input, prev);
	ft_strcat(input, new);
	ft_strcat(input, "\n");
	free(prev);
	free(new);
	return (input);
}

static void	get_stdin(t_cmd *node)
{
	char	*input;
	char	*line;

	input = ft_strdup("");
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			ft_putendl_fd("", STDOUT_FILENO);
			break ;
		}
		if (!ft_strcmp(line, node->d_in_eof))
			break ;
		input = append_input(input, line);
	}
	free(line);
	ft_putendl_fd(input, node->hd_pipe_fd[1]);
	free(input);
}

static void	heredoc_process(t_cmd *node, t_cmd_list *list)
{
	register_heredoc_signal_handler(node);
	get_stdin(node);
	close_all_fd(NULL, node);
	handle_hash_leak();
	ms_terminator(list, 1, 0);
}

void	handle_heredoc(t_cmd *node, t_cmd_list *list)
{
	pid_t	pid;
	int		heredoc_stat;

	if (pipe(node->hd_pipe_fd) == -1)
	{
		perror(NULL);
		ms_terminator(list, 1, errno);
	}
	terminal_state(1);
	pid = fork();
	if (pid == -1)
	{
		perror(NULL);
		ms_terminator(list, 1, errno);
	}
	else if (pid == 0)
		heredoc_process(node, list);
	waitpid(pid, &heredoc_stat, 0);
	ft_printf("heredoc exit at %d\n", heredoc_stat);
	close(node->hd_pipe_fd[1]);
	node->hd_pipe_fd[1] = -1;
}

void	terminal_state(int store_flag)
{
	static struct termios	term_state;

	if (store_flag)
		tcgetattr(STDIN_FILENO, &term_state);
	else
		tcsetattr(STDIN_FILENO, TCSANOW, &term_state);

}
