/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:47:55 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/22 21:19:15 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <unistd.h>
#include <signal.h>
#include "ms_struct.h"
#include "ms_env.h"
#include "ms_execute.h"
#include "ms_signal.h"
#include "libft.h"

static void		readline_signal_handler(int sig);

void	register_signal_handler(void)
{
	rl_catch_signals = 0;
	signal(SIGINT, readline_signal_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
}

void	block_signal(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
}

void	unblock_signal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTERM, SIG_DFL);
}

static void	readline_signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		ms_set_env(MS_EXIT_CODE_KEY, "130");
		ft_printf("^C\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}
