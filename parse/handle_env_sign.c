/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env_sign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 01:30:56 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/20 02:00:15 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parse.h"
#include "ms_env.h"
#include "libft.h"

static char	*change_to_env(char *cmd_str, int *idx, int key_idx)
{
	char	*env_key;
	char	*env_value;
	char	*new_cmd_str;
	char	*following_str;
	char	*temp;

	env_key = ft_substr(cmd_str, *idx, key_idx - *idx);
	env_value = ms_get_env(env_key);
	following_str = ft_substr(cmd_str, key_idx, ft_strlen(cmd_str) - key_idx);
	cmd_str[*idx - 1] = '\0';
	temp = ft_strjoin(cmd_str, env_value);
	*idx = ft_strlen(temp);
	new_cmd_str = ft_strjoin(temp, following_str);
	free(env_key);
	free(following_str);
	free(temp);
	free(cmd_str);
	return (new_cmd_str);
}

void	handle_env_sign(char **cmd_str)
{
	int		idx;
	int		key_idx;

	idx = 0;
	while ((*cmd_str)[idx])
	{
		if ((*cmd_str)[idx] == '\'')
		{
			while ((*cmd_str)[++idx] != '\'' && (*cmd_str)[idx])
				idx++;
		}
		else if ((*cmd_str)[idx] == '$')
		{
			if ((*cmd_str)[++idx] != ' ' || (*cmd_str)[idx])
			{
				key_idx = idx;
				while ((*cmd_str)[key_idx] != ' ' && (*cmd_str)[key_idx])
					key_idx++;
				*cmd_str = change_to_env(*cmd_str, &idx, key_idx);
			}
		}
		else
			idx++;
	}
}
