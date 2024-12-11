/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection_sign.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:30:07 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/11 15:22:21 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./libft/libft.h"

char	*get_redirection_target(char *cmd_str)
{
	char	*temp;
	char	*target;
	int		i;

	temp = ft_strtrim(cmd_str, " \n\t\v\f\r");
	if (!temp)
	{
		//error;
	}
	i = 0;
	while (temp[i] != ' ' || temp[i])
		i++;
	target = ft_substr(temp, 0, i);
	if (!target)
	{
		//error;
	}
	free(temp);
	return (target);
}

int	is_double_input(char *cmd_str, t_cmd *node)
{
	int	i;

	i = 0;
	while (cmd_str[i])
	{
		if (ft_strncmp(cmd_str + i, "<<", 2))
		{
			node->d_input = get_redirection_target(cmd_str + i + 2);
			return (1);
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
		{
			node->s_input = get_redirection_target(cmd_str + i + 2);
			return (1);
		}
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
		{
			node->d_output = get_redirection_target(cmd_str + i + 2);
			return (1);
		}
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
		{
			node->s_output = get_redirection_target(cmd_str + i + 2);
			return (1);
		}
		i++;
	}
	return (0);
}
