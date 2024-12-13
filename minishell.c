/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:12:21 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/13 20:21:27 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ms_execute.h"
#include "ms_env.h"
#include "ms_builtin.h"
#include "ft_hash.h"

static void	handle_hash_leak(void);

//memory 해제
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

static void	handle_hash_leak(void)
{
	free_hash(get_env_hash());
	free_hash(get_builtin_hash());
}
