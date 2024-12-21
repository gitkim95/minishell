/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_close_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:57:47 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/21 17:34:19 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ms_execute.h"

static void	free_pipe(t_cmd_list *list)
{
	int	idx;

	if (!list)
		return ;
	if (!list->pipe_fd)
		return ;
	idx = 0;
	while (idx < list->size - 1)
	{
		free(list->pipe_fd[idx]);
		list->pipe_fd[idx] = NULL;
		idx++;
	}
	free(list->pipe_fd);
	list->pipe_fd = NULL;
}

static void	close_pipe_fd(t_cmd_list *list)
{
	int	i;

	if (!list)
		return ;
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

static void	close_io_fd(t_cmd_list *list)
{
	t_cmd	*node;

	if (!list)
		return ;
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

static void	close_heredoc_fd(t_cmd *node)
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
}

void	close_all_fd(t_cmd_list *list, t_cmd *node)
{
	if (node)
		close_heredoc_fd(node);
	close_io_fd(list);
	close_pipe_fd(list);
	free_pipe(list);
}
