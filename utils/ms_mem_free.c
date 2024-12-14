/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_mem_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:52:34 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/14 17:16:29 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ms_utils.h"
#include "ms_execute.h"

void	free_pipe(int **pipe, int size)
{
	int	i;

	if (!pipe)
		return ;
	i = 0;
	while (i < size - 1)
	{
		free(pipe[i]);
		i++;
	}
	free(pipe);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	clear_ms_list(t_cmd_list *list)
{
	t_cmd	*node;
	t_cmd	*temp;

	close_io_fd(list);
	close_pipe_all(list);
	node = list->head;
	while (node)
	{
		temp = node;
		node = node->next;
		free_split(temp->av);
		free(temp->d_in_eof);
		free(temp);
	}
	free_pipe(list->pipe_fd, list->size);
	list->head = NULL;
	list->tail = NULL;
}

void	free_struct(t_cmd_list *list)
{
	if (list->head)
		clear_ms_list(list);
}
