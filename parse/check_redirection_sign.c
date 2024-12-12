/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection_sign.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:00:51 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/11 21:31:13 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parse.h"
#include "libft.h"

void	input_redirection_sign(char *cmd_str, t_cmd *node)
{
	int		loc;
	char	*target;

	loc = is_double_input(cmd_str);
	if (loc)
	{
		target = get_redirection_target(cmd_str + loc + 2);
		set_eof(target, node);
		free(target);
		return ;
	}
	loc = is_single_input(cmd_str);
	if (loc)
	{
		target = get_redirection_target(cmd_str + loc + 2);
		set_single_input_fd(target, node);
		free(target);
		return ;
	}
}

void	output_redirection_sign(char *cmd_str, t_cmd *node)
{
	int		loc;
	char	*target;

	loc = is_double_output(cmd_str);
	if (loc)
	{
		target = get_redirection_target(cmd_str + loc + 2);
		set_double_output_fd(target, node);
		free(target);
		return ;
	}
	loc = is_single_output(cmd_str);
	if (loc)
	{
		target = get_redirection_target(cmd_str + loc + 2);
		set_single_output_fd(target, node);
		free(target);
		return ;
	}
}
