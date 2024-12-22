/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:12:21 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/22 19:55:30 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ms_execute.h"
#include "ms_env.h"
#include "ms_utils.h"
#include "libft.h"

int	main(int argc, char **argv, char **envp)
{
	t_cmd_list	list;
	int			exit_code;

	(void) argc;
	(void) argv;
	set_env_state(envp);
	script_loop(&list);
	exit_code = ft_atoi(ms_get_env(MS_EXIT_CODE_KEY));
	handle_hash_leak();
	return (exit_code);
}
