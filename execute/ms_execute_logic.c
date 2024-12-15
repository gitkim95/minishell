/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_logic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:36:54 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/15 16:09:09 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"
#include "ms_utils.h"

void	execute_logic(t_cmd_list *list)
{
	pid_t	*pid;

	pid = init_pid_arr(list);
	alloc_pipe_fd(list);
	init_pipe_fd(list);
	process_loop(list, pid);
	// ms_terminator(list, 0, 0);
}
