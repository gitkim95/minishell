/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:55:14 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/15 01:16:21 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ms_execute.h"

void	set_input_descriptor(t_cmd *node, t_cmd_list *list, int idx)
{
	if (node->s_in_fd != -1 || node->d_in_eof)
	{
		if (node->s_in_fd != -1)
			dup2(node->s_in_fd, STDIN_FILENO);
		else
		{
			//heredoc handling;
		}
	}
	else if (node->prev)
	{
		if (node->prev->s_out_fd != -1 || node->d_out_fd != -1)
			return ;
		else
			dup2(list->pipe_fd[idx - 1][0], STDIN_FILENO);
	}
	else
		return ;
}

void	set_output_descriptor(t_cmd *node, t_cmd_list *list, int idx)
{
	if (node->s_out_fd != -1 || node->d_out_fd != -1)
	{
		if (node->s_out_fd != -1)
			dup2(node->s_out_fd, STDOUT_FILENO);
		else
			dup2(node->d_out_fd, STDOUT_FILENO);
	}
	else if (node->next)
		dup2(list->pipe_fd[idx][1], STDOUT_FILENO);
	else
		return ;
}

void	pipe_connect_process(t_cmd *node, t_cmd_list *list, int idx)
{
	set_input_descriptor(node, list, idx);
	set_output_descriptor(node, list, idx);
	close_all_fd(list);
}
