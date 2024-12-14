/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:13:38 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/14 22:22:22 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ms_execute.h"
#include "ms_builtin.h"
#include "ms_utils.h"

void	execute_bulitin(t_cmd *node, t_cmd_list *list, int flag)
{
	int	exit_code;

	exit_code = exec_builtin(node->av);
	if (exit_code == -1)
	{
		//error message
	}
	if (flag == BUILTIN_HAS_OUTPUT)
	{
		clear_ms_list(list);
		if (exit_code > 0)
			exit(0);
		else
			exit(exit_code);
	}
}

void	execute_cmd(t_cmd *node, t_cmd_list *list)
{
	if (execve(node->av[0], node->av, NULL) == -1)
	{
		perror(node->av[0]);
		clear_ms_list(list);
		exit(errno);
	}
}
