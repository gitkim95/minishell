/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_close_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:57:47 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/13 19:47:58 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ms_execute.h"

void	close_pipe_fd(t_cmd_list *list, int idx)
{
	int	i;
	
	i = 0;
	while (i < list->size - 1)
	{
		if (i != idx && i != idx - 1)
		{
			close(list->pipe_fd[i][0]);
			close(list->pipe_fd[i][1]);
		}
		i++;
	}
	if (idx != 0)
		close(list->pipe_fd[idx - 1][1]);
	if (idx != list->size - 1)
		close(list->pipe_fd[idx][0]);
}

void	close_unnecessary_fd(t_cmd *node, t_cmd_list *list, int idx)
{
	close_pipe_fd(list, idx);
	if (node->s_in_fd != -1)
	{
		
	}
	else if (node->d_in_eof)
	{
		//heredoc handling;
	}
	if (node->s_out_fd)
	{

	}
	else if (node->d_out_fd)
	{

	}

}