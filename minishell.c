/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:12:21 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/20 17:10:33 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ms_execute.h"
#include "ms_env.h"
#include "ms_utils.h"

int	main(int argc, char **argv, char **envp)
{
	t_cmd_list	list;

	(void) argc;
	(void) argv;
	set_env_state(envp);
	script_loop(&list);
	handle_hash_leak();
	return (0);
}
