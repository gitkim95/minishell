/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:36:54 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/13 15:52:08 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

void	execute_cmd(t_cmd_list *list)
{
	pid_t	*pid;

	pid = init_pid_arr(list);
	init_pipe_fd(list);
	child_process(list, pid);
	// parents_process();
	
}