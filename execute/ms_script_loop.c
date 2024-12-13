/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_script_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:55:02 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/13 19:59:40 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "ms_parse.h"
#include "ms_execute.h"

void	script_loop(t_cmd_list *list)
{
	char	*input;

	while (1)
	{
		input = readline("$ ");
		add_history(input);
		if (input)
		{
			init_struct(input, list);
			free(input);
			// execute_cmd(list);
		}
		else
			break ;
	}
}