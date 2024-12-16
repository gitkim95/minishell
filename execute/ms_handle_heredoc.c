/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_handle_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:15:16 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/16 12:22:12 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "ms_execute.h"
#include "ms_utils.h"
#include "libft.h"

static void	get_stdin(t_cmd *node, t_cmd_list *list)
{
	char	buf[MS_BUFFER_SIZE + 1];
	int		read_len;
	int		eof_len;

	eof_len = ft_strlen(node->d_in_eof);
	while (1)
	{
		ft_putstr_fd("> ", 2);
		read_len = read(STDIN_FILENO, buf, MS_BUFFER_SIZE);
		if (read_len == -1)
		{
			//error;
		}
		buf[read_len] = '\0';
		if (!read_len || !ft_strncmp(buf, node->d_in_eof, eof_len))
			ms_terminator(list, 0, 1);
		write(STDOUT_FILENO, buf, read_len);
	}
}

static void	set_heredoc_pipe(t_cmd *node)
{
	if (pipe(node->hd_pipe_fd) == -1)
	{
		//error;
	}
}

static void	grandchild_process(t_cmd *node, t_cmd_list *list)
{
	dup2(node->hd_pipe_fd[1], STDOUT_FILENO);
	close_all_fd(list, node);
	get_stdin(node, list);
}

void	handle_heredoc(t_cmd *node, t_cmd_list *list)
{
	pid_t	pid;

	set_heredoc_pipe(node);
	pid = fork();
	if (pid == -1)
	{
		//error;
	}
	else if (pid == 0)
		grandchild_process(node, list);
	waitpid(pid, NULL, 0);
	dup2(node->hd_pipe_fd[0], STDIN_FILENO);
}
