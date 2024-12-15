/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:51:49 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/14 22:26:26 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parse.h"
#include "ms_utils.h"
#include "libft.h"

void	set_isspace_to_blank(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'')
		{
			while (cmd[i + 1] && cmd[i + 1] != '\'')
				i++;
			if (cmd[i + 1] == '\'')
				i++;
		}
		else if (cmd[i] == '\"')
		{
			while (cmd[i + 1] && cmd[i + 1] != '\"')
				i++;
			if (cmd[i + 1] == '\"')
				i++;
		}
		else if (ft_isspace(cmd[i]))
			cmd[i] = ' ';
		i++;
	}
}

void	set_list_struct_zero(t_cmd_list *list)
{
	ft_memset(list, 0, sizeof(t_cmd_list));
}

void	set_cmd_struct_zero(t_cmd *cmd)
{
	cmd->s_in_fd = -1;
	cmd->s_out_fd = -1;
	cmd->d_out_fd = -1;
}

void	init_struct(char *str, t_cmd_list *list)
{
	char	**temp;

	temp = ft_split(str, '|');
	if (!temp)
		exit(ENOMEM);
	make_list(list, temp);
	free_split(temp);
}
