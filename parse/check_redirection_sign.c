/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection_sign.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:00:51 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/21 22:11:36 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parse.h"
#include "ms_utils.h"
#include "libft.h"

static void	delete_redirection(char *cmd, int loc, int sign_size, char *target)
{
	int		idx;
	int		target_idx;

	idx = 0;
	while (idx < sign_size)
	{
		cmd[loc + idx] = ' ';
		idx++;
	}
	while (ft_isspace(cmd[idx + loc]))
	{
		cmd[loc + idx] = ' ';
		idx++;
	}
	target_idx = 0;
	while (target[target_idx] == cmd[loc + idx + target_idx])
	{
		cmd[loc + idx + target_idx] = ' ';
		target_idx++;
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
		delete_redirection(cmd_str, loc, 2, target);
		delete_quotes(&target, &(node->heredoc_quote_flag));
		set_eof(target, node);
		return ;
	}
	loc = is_single_input(cmd_str);
	if (loc >= 0)
	{
		target = get_redirection_target(cmd_str + loc + 1);
		delete_redirection(cmd_str, loc, 1, target);
		delete_quotes(&target, NULL);
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
	if (loc >= 0)
	{
		target = get_redirection_target(cmd_str + loc + 2);
		delete_redirection(cmd_str, loc, 2, target);
		delete_quotes(&target, NULL);
		set_double_output_fd(target, node);
		free(target);
		return ;
	}
	loc = is_single_output(cmd_str);
	if (loc >= 0)
	{
		target = get_redirection_target(cmd_str + loc + 1);
		delete_redirection(cmd_str, loc, 1, target);
		delete_quotes(&target, NULL);
		set_single_output_fd(target, node);
		free(target);
		return ;
	}
}
