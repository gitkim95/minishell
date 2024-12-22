/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_script_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:55:02 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/22 21:51:30 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "ms_parse.h"
#include "ms_env.h"
#include "ms_execute.h"
#include "ms_signal.h"
#include "ms_utils.h"
#include "libft.h"

static void	set_exit_code(int exit_code);
static void	run_input(char *input, t_cmd_list *list);

void	script_loop(t_cmd_list *list)
{
	char	*input;

	while (ms_exit(MS_EXIT_GET))
	{
		register_signal_handler();
		input = readline("minishell$ ");
		if (!input)
		{
			ft_printf("\n");
			break ;
		}
		else if (*input)
		{
			block_signal();
			add_history(input);
			run_input(input, list);
		}
		free(input);
	}
	ft_printf("exit\n");
}

static void	set_exit_code(int exit_code)
{
	char	*exit_str;

	exit_str = ft_itoa(exit_code);
	ms_set_env(MS_EXIT_CODE_KEY, exit_str);
	free(exit_str);
}

static void	run_input(char *input, t_cmd_list *list)
{
	int	exit_code;

	exit_code = init_struct(input, list);
	if (exit_code)
		close_all_fd(list);
	else
		exit_code = execute_logic(list);
	set_exit_code(exit_code);
	ms_terminator(list, 0, 0);
}
