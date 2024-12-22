/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_handle_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:15:16 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/22 16:38:12 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <sys/wait.h>
#include <stdio.h>
#include "ms_execute.h"
#include "ms_signal.h"
#include "ms_utils.h"
#include "ms_parse.h"
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

static void	get_stdin(char *eof, int write_pipe_fd, int flag)
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
		if (!ft_strcmp(line, eof))
			break ;
		if (!flag)
			handle_heredoc_env_sign(&line);
		input = append_input(input, line);
	}
	free(line);
	ft_putstr_fd(input, write_pipe_fd);
	free(input);
}

static void	heredoc_process(t_cmd *node, t_cmd_list *list)
{
	register_heredoc_signal_handler(node, list);
	get_stdin(node->d_in_eof, node->hd_pipe_fd[1], node->heredoc_quote_flag);
	handle_hash_leak();
	close_all_fd(NULL, node);
	ms_terminator(list, 1, 0);
}

int	handle_heredoc(t_cmd *node, t_cmd_list *list)
{
	pid_t	pid;
	int		heredoc_stat;

	if (pipe(node->hd_pipe_fd) == -1)
	{
		perror(NULL);
		ms_terminator(list, 1, errno);
	}
	terminal_state(MS_STORE_TERMINAL_STATE);
	pid = fork();
	if (pid == -1)
	{
		perror(NULL);
		ms_terminator(list, 1, errno);
	}
	else if (pid == 0)
		heredoc_process(node, list);
	waitpid(pid, &heredoc_stat, 0);
	close(node->hd_pipe_fd[1]);
	node->hd_pipe_fd[1] = -1;
	return (ms_exit_status(heredoc_stat));
}
