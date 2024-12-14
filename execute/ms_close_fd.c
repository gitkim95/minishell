/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_close_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:57:47 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/14 18:16:23 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ms_execute.h"

void	close_pipe_all(t_cmd_list *list)
{
	int	i;
	
	i = 0;
	while (i < list->size - 1)
	{
		close(list->pipe_fd[i][0]);
		close(list->pipe_fd[i][1]);
		i++;
	}
}

void	close_io_fd(t_cmd_list *list)
{
	t_cmd	*node;

	node = list->head;
	while (node)
	{
		if (node->s_in_fd != -1)
			close(node->s_in_fd);
		if (node->s_out_fd != -1)
			close(node->s_out_fd);
		if (node->d_out_fd != -1)
			close(node->d_out_fd);
		node = node->next;
	}
}

void	close_pipe_fd(t_cmd_list *list, int idx)
{
	int	i;

	i = 0;
	while (i < list->size - 1)
	{
		if (i != idx && i != idx - 1)
		{
			close(list->pipe_fd[i][0]);
			close(list->pipe_fd[i][1]);
		}
		i++;
	}
	if (idx != 0)
		close(list->pipe_fd[idx - 1][1]);
	if (idx != list->size - 1)
		close(list->pipe_fd[idx][0]);
}

void	close_unnecessary_fd(t_cmd *node, t_cmd_list *list, int idx)
{
	close_pipe_fd(list, idx);
	if (node->s_in_fd != -1)
	{
		if (idx != 0)
			close(list->pipe_fd[idx - 1][0]);
	}
	else if (node->d_in_eof)
	{
		//heredoc handling;
	}
	if (node->s_out_fd != -1 || node->d_out_fd != -1)
	{
		if (node->s_out_fd != -1)
			close(node->s_out_fd);
		else
			close(node->d_out_fd);
		close(list->pipe_fd[idx][1]);
	}
}
