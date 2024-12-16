/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:13:38 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/16 13:57:44 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ms_execute.h"
#include "ms_builtin.h"
#include "ms_env.h"
#include "ms_utils.h"

void	execute_bulitin(t_cmd *node, t_cmd_list *list, int flag)
{
	exec_builtin(node->av);
	if (flag == BUILTIN_HAS_OUTPUT)
	{
		handle_hash_leak();
		ms_terminator(list, 0, 1);
	}
}

void	execute_cmd(t_cmd *node, t_cmd_list *list)
{
	char	**envp;

	envp = get_env_array();
	if (execve(node->av[0], node->av, envp) == -1)
	{
		perror(node->av[0]);
		free_split(envp);
		handle_hash_leak();
		ms_terminator(list, errno, 1);
	}
}
