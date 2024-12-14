/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_close_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:57:47 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/15 02:38:20 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ms_execute.h"

void	free_pipe(t_cmd_list *list)
{
	int	idx;

	if (!list->pipe_fd)
		return ;
	idx = 0;
	while (idx < list->size - 1)
	{
		free(list->pipe_fd[idx]);
		idx++;
	}
	free(list->pipe_fd);
}

void	close_pipe_fd(t_cmd_list *list)
{
	int	i;

	i = 0;
	while (i < list->size - 1)
	{
		if (list->pipe_fd[i][0] != -1)
		{
			close(list->pipe_fd[i][0]);
			list->pipe_fd[i][0] = -1;
		}
		if (list->pipe_fd[i][1] != -1)
		{
			close(list->pipe_fd[i][1]);
			list->pipe_fd[i][1] = -1;
		}
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
		{
			close(node->s_in_fd);
			node->s_in_fd = -1;
		}
		if (node->s_out_fd != -1)
		{
			close(node->s_out_fd);
			node->s_out_fd = -1;
		}
		if (node->d_out_fd != -1)
		{
			close(node->d_out_fd);
			node->d_out_fd = -1;
		}
		node = node->next;
	}
}

void	close_all_fd(t_cmd_list *list)
{
	close_io_fd(list);
	close_pipe_fd(list);
	free_pipe(list);
}
