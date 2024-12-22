/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:47:55 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/22 21:52:01 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termios.h>
#include <signal.h>
#include "ms_struct.h"
#include "ms_signal.h"
#include "ms_utils.h"
#include "ms_execute.h"
#include "libft.h"

static void			heredoc_signal_handler(int sig);
static t_cmd_list	*heredoc_list(t_cmd_list *list);

void	register_heredoc_signal_handler(t_cmd_list *list)
{
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
	t_cmd_list	*list;

	list = heredoc_list(NULL);
	if (sig == SIGINT)
	{
		ft_printf("^C\n");
		close_all_fd(list);
		terminal_state(MS_RESTORE_TERMINAL_STATE);
		handle_hash_leak();
		ms_terminator(list, 1, 128 + SIGINT);
	}
}

static t_cmd_list	*heredoc_list(t_cmd_list *list)
{
	static t_cmd_list	*heredoc_list;

	if (list)
		heredoc_list = list;
	return (heredoc_list);
}
