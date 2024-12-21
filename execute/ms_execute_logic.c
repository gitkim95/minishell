/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_logic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:36:54 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/22 16:45:11 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ms_builtin.h"
#include "ms_execute.h"
#include "ms_utils.h"

static void	restore_std_fds(int *std_fds)
{
	dup2(std_fds[0], STDIN_FILENO);
	dup2(std_fds[1], STDOUT_FILENO);
	dup2(std_fds[2], STDERR_FILENO);
	close(std_fds[0]);
	close(std_fds[1]);
	close(std_fds[2]);
}

static void	store_std_fds(int *std_fds)
{
	std_fds[0] = dup(STDIN_FILENO);
	std_fds[1] = dup(STDOUT_FILENO);
	std_fds[2] = dup(STDERR_FILENO);
}

void	execute_logic(t_cmd_list *list)
{
	pid_t	*pid;
	int		std_fds[3];

	if (list->size > 1)
	{
		alloc_pipe_fd(list);
		init_pipe_fd(list);
	}
	if (list->size == 1 && is_builtin(list->head->av[0]))
	{
		store_std_fds(std_fds);
		pipe_connect(list->head, list, 0);
		exec_builtin(list->head->av);
		restore_std_fds(std_fds);
	}
	else
	{
		pid = init_pid_arr(list);
		process_loop(list, pid);
	}
	ms_terminator(list, 0, 0);
}
