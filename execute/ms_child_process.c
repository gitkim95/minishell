/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:37:35 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/13 21:41:19 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ms_execute.h"
#include "ms_builtin.h"
#include <stdio.h>

void	child_process(t_cmd_list *list, pid_t *pid)
{
	t_cmd	*node;
	int		idx;

	node = list->head;
	idx = 0;
	while (idx < list->size)
	{
		if (is_builtin(node->av[0]))
			execute_bulitin(node, list);
		else
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
				printf("thisistest : %s\n", node->av[0]);
				execute_cmd(node, list);
			}
		}
			idx++;
			node = node->next;
	}
}
