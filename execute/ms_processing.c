/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_processing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:37:35 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/21 22:30:18 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include "ms_env.h"
#include "ms_execute.h"
#include "ms_builtin.h"
#include "ms_signal.h"
#include "ms_utils.h"
#include "libft.h"

static void	temp_close_heredoc_fd(t_cmd_list *list)
{
	t_cmd	*node;

	if (!list)
		return ;
	node = list->head;
	while (node)
	{
		if (node->hd_pipe_fd[0] != -1)
		{
			close(node->hd_pipe_fd[0]);
			node->hd_pipe_fd[0] = -1;
		}
		if (node->hd_pipe_fd[1] != -1)
		{
			close(node->hd_pipe_fd[1]);
			node->hd_pipe_fd[1] = -1;
		}
		node = node->next;
	}
}

static void	parent_process(t_cmd_list *list, pid_t *pid)
{
	char	*exit_str;
	int		exit_code;
	int		idx;

	temp_close_heredoc_fd(list);
	close_all_fd(list, NULL);
	idx = 0;
	while (idx < list->size)
	{
		if (pid[idx] != -2)
			waitpid(pid[idx], &exit_code, 0);
		idx++;
	}
	exit_str = ft_itoa(ms_exit_status(exit_code));
	ms_set_env("0", exit_str);
	free(exit_str);
	free(pid);
}

static void	child_process(t_cmd *node, t_cmd_list *list, int idx)
{
	int	exit_code;

	pipe_connect(node, list, idx);
	if (is_builtin(node->av[0]))
		exit_code = exec_builtin(node->av);
	else
		exit_code = execute_cmd(node);
	handle_hash_leak();
	ms_terminator(list, 1, exit_code);
}

void	process_loop(t_cmd_list *list, pid_t *pid)
{
	t_cmd	*node;
	int		idx;

	node = list->head;
	idx = 0;
	while (idx < list->size)
	{
		pid[idx] = fork();
		if (pid[idx] == -1)
		{
			perror(NULL);
			ms_terminator(list, 1, errno);
		}
		else if (pid[idx] == 0)
		{
			free(pid);
			if (idx == 0)
				unblock_signal();
			child_process(node, list, idx);
		}
		idx++;
		node = node->next;
	}
	parent_process(list, pid);
}
