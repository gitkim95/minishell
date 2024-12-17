/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_handle_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:15:16 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/17 20:10:59 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "ms_execute.h"
#include "ms_utils.h"
#include "libft.h"

static void	get_stdin(t_cmd *node, t_cmd_list *list)
{
	char	buf[MS_BUFFER_SIZE + 1];
	int		read_len;

	while (1)
	{
		ft_putstr_fd("> ", 2);
		read_len = read(STDIN_FILENO, buf, MS_BUFFER_SIZE);
		if (read_len == -1)
		{
			perror(NULL);
			ms_terminator(list, 1, errno);
		}			
		buf[read_len - 1] = '\0';
		if (!read_len || !ft_strcmp(buf, node->d_in_eof))
			return ;
		ft_putendl_fd(buf, STDOUT_FILENO);
	}
}

static void	heredoc_process(t_cmd *node, t_cmd_list *list)
{
	dup2(node->hd_pipe_fd[1], STDOUT_FILENO);
	close_all_fd(list, node);
	get_stdin(node, list);
	handle_hash_leak();
	ms_terminator(list, 1, 0);
}

void	handle_heredoc(t_cmd *node, t_cmd_list *list)
{
	pid_t	pid;

	if (pipe(node->hd_pipe_fd) == -1)
	{
		perror(NULL);
		ms_terminator(list, 1, errno);
	}
	pid = fork();
	if (pid == -1)
	{
		perror(NULL);
		ms_terminator(list, 1, errno);
	}
	else if (pid == 0)
		heredoc_process(node, list);
	waitpid(pid, NULL, 0);
	dup2(node->hd_pipe_fd[0], STDIN_FILENO);
}
