/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:55:14 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/16 13:57:50 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ms_execute.h"

static void	set_input_descriptor(t_cmd *node, t_cmd_list *list, int idx)
{
	if (node->s_in_fd != -1 || node->d_in_eof)
	{
		if (node->s_in_fd != -1)
			dup2(node->s_in_fd, STDIN_FILENO);
		else
			handle_heredoc(node, list);
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

static void	set_output_descriptor(t_cmd *node, t_cmd_list *list, int idx)
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

void	pipe_connect(t_cmd *node, t_cmd_list *list, int idx)
{
	set_input_descriptor(node, list, idx);
	set_output_descriptor(node, list, idx);
	close_all_fd(list, node);
}
