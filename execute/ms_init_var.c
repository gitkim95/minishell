/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:16:59 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/17 17:05:03 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ms_execute.h"
#include "ms_utils.h"
#include "libft.h"

void	alloc_pipe_fd(t_cmd_list *list)
{
	int	idx;

	list->pipe_fd = (int **)malloc(sizeof(int *) * (list->size - 1));
	if (!list->pipe_fd)
		ms_terminator(list, 1, errno);
	idx = 0;
	while (idx < list->size - 1)
	{
		list->pipe_fd[idx] = (int *)malloc(sizeof(int) * 2);
		if (!list->pipe_fd[idx])
			ms_terminator(list, 1, errno);
		list->pipe_fd[idx][0] = -1;
		list->pipe_fd[idx][1] = -1;
		idx++;
	}
}

void	init_pipe_fd(t_cmd_list *list)
{
	int	idx;

	idx = 0;
	while (idx < list->size - 1)
	{
		if (pipe(list->pipe_fd[idx]) == -1)
			ms_terminator(list, 1, errno);
		idx++;
	}
}

pid_t	*init_pid_arr(t_cmd_list *list)
{
	pid_t	*pid;

	pid = (pid_t *)malloc(sizeof(pid_t) * list->size);
	if (!pid)
		ms_terminator(list, 1, errno);
	ft_memset(pid, -2, sizeof(pid_t) * list->size);
	return (pid);
}
