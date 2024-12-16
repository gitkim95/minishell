/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection_sign.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:00:51 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/16 12:15:08 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parse.h"
#include "ms_utils.h"
#include "libft.h"

static void	delete_redirection(char *cmd, int loc, int sign_size)
{
	int		idx;

	idx = 0;
	while (idx < sign_size)
	{
		cmd[loc + idx] = ' ';
		idx++;
	}
	while (ft_isspace(cmd[idx + loc]))
	{
		cmd[idx + loc] = ' ';
		idx++;
	}
	while (cmd[idx + loc] && !ft_isspace(cmd[idx + loc]))
	{
		cmd[idx + loc] = ' ';
		idx++;
	}
}

void	input_redirection_sign(char *cmd_str, t_cmd *node)
{
	int		loc;
	char	*target;

	loc = is_double_input(cmd_str);
	if (loc >= 0)
	{
		target = get_redirection_target(cmd_str + loc + 2);
		set_eof(target, node);
		delete_redirection(cmd_str, loc, 2);
		return ;
	}
	loc = is_single_input(cmd_str);
	if (loc >= 0)
	{
		target = get_redirection_target(cmd_str + loc + 1);
		set_single_input_fd(target, node);
		free(target);
		delete_redirection(cmd_str, loc, 1);
		return ;
	}
}

void	output_redirection_sign(char *cmd_str, t_cmd *node)
{
	int		loc;
	char	*target;

	loc = is_double_output(cmd_str);
	if (loc >= 0)
	{
		target = get_redirection_target(cmd_str + loc + 2);
		set_double_output_fd(target, node);
		free(target);
		delete_redirection(cmd_str, loc, 2);
		return ;
	}
	loc = is_single_output(cmd_str);
	if (loc >= 0)
	{
		target = get_redirection_target(cmd_str + loc + 1);
		set_single_output_fd(target, node);
		free(target);
		delete_redirection(cmd_str, loc, 1);
		return ;
	}
}
