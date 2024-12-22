/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_logic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:36:54 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/22 19:37:03 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ms_builtin.h"
#include "ms_env.h"
#include "ms_execute.h"
#include "ms_utils.h"
#include "libft.h"

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

static void	set_exit_code(int exit_code)
{
	char	*exit_str;

	exit_str = ft_itoa(exit_code);
	ms_set_env(MS_EXIT_CODE_KEY, exit_str);
	free(exit_str);
}

void	execute_logic(t_cmd_list *list)
{
	pid_t	*pid;
	int		std_fds[3];
	int		exit_code;

	if (list->size > 1)
	{
		alloc_pipe_fd(list);
		init_pipe_fd(list);
	}
	if (list->size == 1 && is_builtin(list->head->av[0]))
	{
		store_std_fds(std_fds);
		pipe_connect(list->head, list, 0);
		exit_code = exec_builtin(list->head->av);
		restore_std_fds(std_fds);
	}
	else
	{
		pid = init_pid_arr(list);
		exit_code = process_loop(list, pid);
	}
	set_exit_code(exit_code);
	ms_terminator(list, 0, 0);
}
