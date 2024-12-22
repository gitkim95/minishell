/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_mem_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:52:34 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/22 21:14:12 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_hash.h"
#include "ms_utils.h"
#include "ms_execute.h"
#include "ms_env.h"
#include "ms_builtin.h"

void	handle_hash_leak(void)
{
	free_hash(get_env_hash());
	free_hash(get_builtin_hash());
}

void	free_pipe(t_cmd_list *list)
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

	node = list->head;
	while (node)
	{
		temp = node;
		node = node->next;
		free_split(temp->av);
		free(temp->d_in_eof);
		free(temp);
	}
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
}

void	ms_terminator(t_cmd_list *list, int exit_flag, int exit_code)
{
	if (list->head)
		clear_ms_list(list);
	if (exit_flag)
		exit(exit_code);
}
