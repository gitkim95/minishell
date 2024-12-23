/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:22:14 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/23 17:38:11 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parse.h"
#include "ms_env.h"
#include "libft.h"

void	handle_double_quotes_env(char **cmd_str, int *key_idx, int *idx)
{
	(*idx)++;
	while ((*cmd_str)[*idx] != '\"')
	{
		if ((*cmd_str)[*idx] == '$')
		{
			if (ft_isalnum((*cmd_str)[++(*idx)]) || (*cmd_str)[*idx] == '?')
			{
				get_key_idx(*cmd_str, key_idx, *idx);
				*cmd_str = change_to_env(*cmd_str, idx, *key_idx, 0);
			}
		}
		(*idx)++;
	}
	(*idx)++;
}

void	get_key_idx(char *cmd_str, int *key_idx, int idx)
{
	*key_idx = idx;
	while (ft_isalnum(cmd_str[*key_idx]))
		(*key_idx)++;
}

char	*fit_ifs(char *env_value)
{
	char	*ifs_env;
	char	*ifs_value;
	int		idx;

	ifs_env = ft_strdup(env_value);
	if (!ifs_env)
		return (NULL);
	ifs_value = ms_get_env(MS_IFS_KEY);
	idx = 0;
	while (ifs_env[idx])
	{
		if (ft_strchr(ifs_value, ifs_env[idx]))
			ifs_env[idx] = ' ';
		idx++;
	}
	return (ifs_env);
}
