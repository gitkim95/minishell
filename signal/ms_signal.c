/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:47:55 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/21 13:15:32 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <unistd.h>
#include <signal.h>
#include "ms_struct.h"
#include "ms_execute.h"
#include "ms_message.h"
#include "ms_signal.h"
#include "libft.h"

static void		readline_signal_handler(int sig);
static void		heredoc_signal_handler(int sig);
static t_cmd	*heredoc_data(t_cmd *cmd)
{
	static t_cmd	*cmd_context;

	if (cmd)
		cmd_context = cmd;
	return (cmd_context);
}

void	register_signal_handler(void)
{
	rl_catch_signals = 0;
	signal(SIGINT, readline_signal_handler);
	signal(SIGQUIT, readline_signal_handler);
}

void	register_heredoc_signal_handler(t_cmd *cmd)
{
	heredoc_data(cmd);
	signal(SIGINT, heredoc_signal_handler);
}

void	block_signal(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	unblock_signal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

static void	readline_signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

static void	heredoc_signal_handler(int sig)
{
	t_cmd	*cmd;

	cmd = heredoc_data(NULL);
	if (sig == SIGINT)
	{
		close(cmd->hd_pipe_fd[0]);
		close(cmd->hd_pipe_fd[1]);
		// readline_signal_handler(sig);
		terminal_state(0);
		exit(1);
	}
}
