/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:37:35 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/12 16:52:24 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ms_execute.h"

void	pipe_connect_process(t_cmd *node, int idx)
{
	if (node->s_in_fd != -1)
		dup2(node->s_in_fd, STDIN_FILENO);
	else
		dup2(cmd->pipe_fd[idx - 1][0], STDIN_FILENO);

	if (node->s_out_fd != -1)
		dup2(node->s_out_fd, STDOUT_FILENO);
	if (node->d_out_fd != -1)
		dup2(node->d_out_fd, STDOUT_FILENO);
	// if (idx == 0)
	// {
	// 	dup2(cmd->input_fd, STDIN_FILENO);
	// 	dup2(cmd->pipe_fd[idx][1], STDOUT_FILENO);
	// 	close_child_first(cmd);
	// }
	// else if (idx == cmd->arg_size - 1)
	// {
	// 	dup2(cmd->pipe_fd[idx - 1][0], STDIN_FILENO);
	// 	dup2(cmd->output_fd, STDOUT_FILENO);
	// 	close_child_last(cmd, idx);
	// }
	// else
	// {
	// 	dup2(cmd->pipe_fd[idx - 1][0], STDIN_FILENO);
	// 	dup2(cmd->pipe_fd[idx][1], STDOUT_FILENO);
	// 	close_child_middle(cmd, idx);
	// }
}

void	child_process(t_cmd_list *list, pid_t *pid)
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
			//error;
		}
		else if (pid[idx] == 0)
		{
			free(pid);
			pipe_connect_process(node, idx);
		}
		idx++;
		node = node->next;
	}
}
