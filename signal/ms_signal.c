/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:47:55 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/15 18:20:35 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <signal.h>
#include "ms_message.h"
#include "ms_signal.h"
#include "libft.h"

static void	readline_signal_handler(int sig);

void	register_signal_hander(void)
{
	rl_catch_signals = 0;
	signal(SIGINT, readline_signal_handler);
	signal(SIGQUIT, readline_signal_handler);
}

void	reset_signal_hander(void)
{
	rl_catch_signals = 1;
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
