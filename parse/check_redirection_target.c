/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection_target.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:30:07 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/11 21:31:14 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parse.h"
#include "libft.h"

char	*get_redirection_target(char *cmd_str)
{
	char	*temp;
	char	*target;
	int		i;

	temp = ft_strtrim(cmd_str, " \n\t\v\f\r");
	if (!temp)
		exit(ENOMEM);
	i = 0;
	while (temp[i] || temp[i] != ' ')
		i++;
	target = ft_substr(temp, 0, i);
	if (!target)
		exit(ENOMEM);
	free(temp);
	if (!*target)
		return (NULL);
	return (target);
}

int	is_double_input(char *cmd_str)
{
	int		i;

	i = 0;
	while (cmd_str[i])
	{
		if (!ft_strncmp(cmd_str + i, "<<", 2))
			return (i);
		i++;
	}
	return (0);
}

int	is_single_input(char *cmd_str)
{
	int		i;

	i = 0;
	while (cmd_str[i])
	{
		if (!ft_strncmp(cmd_str + i, "<", 1))
			return (i);
		i++;
	}
	return (0);
}

int	is_double_output(char *cmd_str)
{
	int		i;

	i = 0;
	while (cmd_str[i])
	{
		if (!ft_strncmp(cmd_str + i, ">>", 2))
			return (i);
		i++;
	}
	return (0);
}

int	is_single_output(char *cmd_str)
{
	int		i;

	i = 0;
	while (cmd_str[i])
	{
		if (!ft_strncmp(cmd_str + i, ">", 1))
			return (i);
		i++;
	}
	return (0);
}
