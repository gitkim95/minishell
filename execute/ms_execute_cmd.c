/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:13:38 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/15 16:02:32 by gitkim           ###   ########.fr       */
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
	exec_builtin(node->av);
	if (flag == BUILTIN_HAS_OUTPUT)
		ms_terminator(list, 0, 1);
}

void	execute_cmd(t_cmd *node, t_cmd_list *list)
{
	if (execve(node->av[0], node->av, NULL) == -1)
	{
		perror(node->av[0]);
		ms_terminator(list, errno, 1);
	}
}
