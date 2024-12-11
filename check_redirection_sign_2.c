/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection_sign_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:00:51 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/11 16:07:26 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	check_input_redirection_sign(char *cmd_str, t_cmd *node)
{
	int	loc;

	loc = is_double_input(cmd_str, node);
	if (loc)
		return ;
	loc = is_single_input(cmd_str, node);
	if (loc)
		return ;
}

void	check_output_redirection_sign(char *cmd_str, t_cmd *node)
{
	int	loc;

	loc = is_double_output(cmd_str, node);
	if (loc)
		return ;
	loc = is_single_output(cmd_str, node);
	if (loc)
		return ;
}
