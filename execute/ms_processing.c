/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_processing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:37:35 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/22 21:51:09 by hwilkim          ###   ########.fr       */
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

static int	parent_process(t_cmd_list *list, pid_t *pid)
{
	int		exit_code;
	int		idx;

	exit_code = ft_atoi(ms_get_env(MS_EXIT_CODE_KEY));
	close_all_fd(list);
	idx = 0;
	while (idx < list->size)
	{
		if (pid[idx] != PID_INIT)
			waitpid(pid[idx], &exit_code, 0);
		idx++;
	}
	free(pid);
	return (ms_exit_status(exit_code));
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

int	process_loop(t_cmd_list *list, pid_t *pid)
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
			unblock_signal();
			child_process(node, list, idx);
		}
		idx++;
		node = node->next;
	}
	return (parent_process(list, pid));
}
