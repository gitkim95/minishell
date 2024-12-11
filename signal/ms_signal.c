/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:47:55 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/11 22:11:44 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <signal.h>
#include "ms_message.h"
#include "ms_signal.h"

void	register_signal_hander()
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}

void	reset_signal_hander()
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	sigint_handler(int sig)
{
	rl_replace_line(MS_NEW_LINE_STR, 0);
	rl_on_new_line();
	rl_redisplay();
}

void	sigquit_handler(int sig)
{
	rl_replace_line(MS_EMPTY_STR, 1);
	rl_redisplay();
}
