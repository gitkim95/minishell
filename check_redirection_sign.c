/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection_sign.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:30:07 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/11 14:01:29 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./libft/libft.h"

char	*get_redirection_target(char *cmd_str)
{
	
}

int	is_double_input(char *cmd_str, t_cmd *node)
{
	int	i;

	i = 0;
	while (cmd_str[i])
	{
		if (ft_strncmp(cmd_str + i, "<<", 2))
		{
			node->d_input = get_redirection_target(cmd_str + i);
			return (i);
		}
		i++;
	}
	return (0);
}

int	is_single_input(char *cmd_str, t_cmd *node)
{
	int	i;

	i = 0;
	while (cmd_str[i])
	{
		if (ft_strncmp(cmd_str + i, "<", 1))
			return (i);
		i++;
	}
	return (0);
}

int	is_double_output(char *cmd_str, t_cmd *node)
{
int	i;

	i = 0;
	while (cmd_str[i])
	{
		if (ft_strncmp(cmd_str + i, ">>", 2))
			return (i);
		i++;
	}
	return (0);
}

int	is_single_output(char *cmd_str, t_cmd *node)
{
	int	i;

	i = 0;	
	while (cmd_str[i])
	{
		if (ft_strncmp(cmd_str + i, ">", 1))
			return (i);
		i++;
	}
	return (0);
}
