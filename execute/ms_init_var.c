/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:16:59 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/12 15:49:28 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

void	init_pipe_fd(t_cmd_list *list)
{
	t_cmd	*node;

	node = list->head;
	while (node)
	{
		if (pipe(node->pipe_fd) == -1)
		{
			//error;
		}
		node = node->next;
	}
}

pid_t	*init_pid_arr(t_cmd_list *list)
{
	pid_t	*pid;

	pid = (pid_t *)malloc(sizeof(pid_t) * list->size);
	if (!pid)
	{
		//error;
	}
	return (pid);
}