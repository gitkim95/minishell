/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:12:21 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/15 02:27:30 by gitkim           ###   ########.fr       */
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
