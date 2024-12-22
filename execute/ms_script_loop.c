/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_script_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:55:02 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/22 19:49:52 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "ms_parse.h"
#include "ms_execute.h"
#include "ms_signal.h"
#include "ms_utils.h"
#include "libft.h"

void	script_loop(t_cmd_list *list)
{
	char	*input;

	while (ms_exit(MS_EXIT_GET))
	{
		register_signal_handler();
		input = readline("$ ");
		if (!input)
		{
			ft_printf("\n");
			break ;
		}
		else if (*input)
		{
			block_signal();
			add_history(input);
			init_struct(input, list);
			execute_logic(list);
		}
		free(input);
	}
	ft_printf("exit\n");
}
