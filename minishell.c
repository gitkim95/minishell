/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:12:21 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/15 18:31:05 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ms_execute.h"
#include "ms_env.h"
#include "ms_signal.h"
#include "ms_utils.h"

int	main(int argc, char **argv, char **envp)
{
	t_cmd_list	list;

	(void) argc;
	(void) argv;
	register_signal_hander();
	set_env_state(envp);
	script_loop(&list);
	handle_hash_leak();
	return (0);
}
