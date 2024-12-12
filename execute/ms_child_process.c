/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:37:35 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/12 18:29:21 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ms_execute.h"

void	set_io_last_cmd(t_cmd *node, t_cmd_list *list, int idx)
{
	dup2(list->pipe_fd[idx - 1][0], STDIN_FILENO);
	dup2(list->output_fd, STDOUT_FILENO);
	close_child_last(list, idx);
}
void	set_io_first_cmd(t_cmd *node, t_cmd_list *list, int idx)
{
	if (node->s_out_fd == -1 && node->d_out_fd == -1)
		dup2(list->pipe_fd[idx][1], STDOUT_FILENO);
	close_child_first(list);
}


void	set_io_middle_cmd(t_cmd *node, t_cmd_list *list, int idx)
{
	dup2(list->pipe_fd[idx - 1][0], STDIN_FILENO);
	dup2(list->pipe_fd[idx][1], STDOUT_FILENO);
	close_child_middle(list, idx);
}

void	pipe_connect_process(t_cmd *node, t_cmd_list *list, int idx)
{
	if (node->s_in_fd != -1)
		dup2(node->s_in_fd, STDIN_FILENO);
	if (node->s_out_fd != -1)
		dup2(node->s_out_fd, STDOUT_FILENO);
	if (node->d_out_fd != -1)
		dup2(node->d_out_fd, STDOUT_FILENO);
	if (idx == list->size - 1)
		set_io_last_cmd(node, list, idx);
	else if (idx == 0)
		set_io_first_cmd(node, list, idx);
	else
		set_io_middle_cmd(node, list, idx);
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
			pipe_connect_process(node, list, idx);
		}
		idx++;
		node = node->next;
	}
}
