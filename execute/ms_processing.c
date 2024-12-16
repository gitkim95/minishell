/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_processing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:37:35 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/16 13:57:48 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include "ms_execute.h"
#include "ms_builtin.h"

static void	parent_process(t_cmd_list *list, pid_t *pid)
{
	int	idx;

	close_all_fd(list, NULL);
	idx = 0;
	while (idx < list->size)
	{
		if (pid[idx] != -2)
			waitpid(pid[idx], NULL, 0);
		idx++;
	}
	free(pid);
}

static void	child_process(t_cmd *node, t_cmd_list *list, int idx)
{
	pipe_connect(node, list, idx);
	if (is_builtin(node->av[0]) == BUILTIN_HAS_OUTPUT)
		execute_bulitin(node, list, BUILTIN_HAS_OUTPUT);
	else
		execute_cmd(node, list);
}

void	process_loop(t_cmd_list *list, pid_t *pid)
{
	t_cmd	*node;
	int		idx;

	node = list->head;
	idx = 0;
	while (idx < list->size)
	{
		if (is_builtin(node->av[0]) == BUILTIN_NO_OUTPUT)
			execute_bulitin(node, list, BUILTIN_NO_OUTPUT);
		else
		{
			pid[idx] = fork();
			if (pid[idx] == -1)
				perror(NULL);
			else if (pid[idx] == 0)
			{
				free(pid);
				child_process(node, list, idx);
			}
		}
		idx++;
		node = node->next;
	}
	parent_process(list, pid);
}
