/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:13:38 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/22 16:44:52 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ms_execute.h"
#include "ms_builtin.h"
#include "ms_env.h"
#include "ms_utils.h"

static int	execve_errno_to_exit_code(int execve_errno);

int	execute_cmd(t_cmd *node)
{
	char	**envp;

	envp = get_env_array();
	if (!node->av[0] || execve(node->av[0], node->av, envp) == -1)
	{
		if (node->av[0] && *(node->av[0]))
			perror(node->av[0]);
		free_split(envp);
		return (execve_errno_to_exit_code(errno));
	}
	return (0);
}

static int	execve_errno_to_exit_code(int execve_errno)
{
	int	exit_code;

	if (execve_errno == ENOENT)
		exit_code = 127;
	else if (execve_errno == EACCES)
		exit_code = 126;
	else
		exit_code = 0;
	return (exit_code);
}
