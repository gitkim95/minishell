/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_script_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:55:02 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/20 19:32:49 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "ms_parse.h"
#include "ms_execute.h"
#include "ms_signal.h"

void	script_loop(t_cmd_list *list)
{
	char	*input;

	while (1)
	{
		register_signal_handler();
		input = readline("$ ");
		add_history(input);
		if (input)
		{
			block_signal();
			init_struct(input, list);
			free(input);
			execute_logic(list);
		}
		else
			break ;
	}
}
