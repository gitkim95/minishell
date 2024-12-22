/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:47:55 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/22 16:40:55 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termios.h>
#include <signal.h>
#include "ms_struct.h"
#include "ms_signal.h"
#include "ms_utils.h"
#include "libft.h"

static void			heredoc_signal_handler(int sig);
static t_cmd		*heredoc_node(t_cmd *node);
static t_cmd_list	*heredoc_list(t_cmd_list *list);

void	register_heredoc_signal_handler(t_cmd *node, t_cmd_list *list)
{
	heredoc_node(node);
	heredoc_list(list);
	signal(SIGINT, heredoc_signal_handler);
}

void	terminal_state(int store_flag)
{
	static struct termios	term_state;

	if (store_flag)
		tcgetattr(STDIN_FILENO, &term_state);
	else
		tcsetattr(STDIN_FILENO, TCSANOW, &term_state);
}

static void	heredoc_signal_handler(int sig)
{
	t_cmd		*node;
	t_cmd_list	*list;

	node = heredoc_node(NULL);
	list = heredoc_list(NULL);
	if (sig == SIGINT)
	{
		close(node->hd_pipe_fd[0]);
		close(node->hd_pipe_fd[1]);
		terminal_state(MS_RESTORE_TERMINAL_STATE);
		handle_hash_leak();
		ms_terminator(list, 1, 128 + SIGINT);
		exit(128 + SIGINT);
	}
}

static t_cmd	*heredoc_node(t_cmd *node)
{
	static t_cmd	*heredoc_node;

	if (node)
		heredoc_node = node;
	return (heredoc_node);
}

static t_cmd_list	*heredoc_list(t_cmd_list *list)
{
	static t_cmd_list	*heredoc_list;

	if (list)
		heredoc_list = list;
	return (heredoc_list);
}
