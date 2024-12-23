/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env_sign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 01:30:56 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/23 17:38:45 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parse.h"
#include "ms_env.h"
#include "libft.h"

char	*change_to_env(char *cmd_str, int *idx, int key_idx, int ifs_flag)
{
	char	*env_key;
	char	*env_value;
	char	*new_cmd_str;
	char	*following_str;
	char	*temp;

	if (key_idx == *idx)
		key_idx++;
	env_key = ft_substr(cmd_str, *idx, key_idx - *idx);
	env_value = ms_get_env(env_key);
	if (ifs_flag)
		env_value = fit_ifs(env_value);
	following_str = ft_substr(cmd_str, key_idx, ft_strlen(cmd_str));
	cmd_str[*idx - 1] = '\0';
	temp = ft_strjoin(cmd_str, env_value);
	*idx = ft_strlen(temp) - 1;
	new_cmd_str = ft_strjoin(temp, following_str);
	if (ifs_flag)
		free(env_value);
	free(env_key);
	free(following_str);
	free(temp);
	free(cmd_str);
	return (new_cmd_str);
}

void	handle_env_sign(char **cmd_str)
{
	int	idx;
	int	key_idx;

	idx = 0;
	while ((*cmd_str)[idx])
	{
		if ((*cmd_str)[idx] == '\'')
			skip_quote(*cmd_str, &idx, '\'');
		else if ((*cmd_str)[idx] == '\"')
			handle_double_quotes_env(cmd_str, &key_idx, &idx);
		else if ((*cmd_str)[idx] == '$')
		{
			if (ft_isalnum((*cmd_str)[++idx]) || (*cmd_str)[idx] == '?')
			{
				get_key_idx(*cmd_str, &key_idx, idx);
				*cmd_str = change_to_env(*cmd_str, &idx, key_idx, 1);
			}
		}
		else
			idx++;
	}
}

void	handle_heredoc_env_sign(char **input)
{
	int	idx;
	int	key_idx;

	idx = 0;
	while ((*input)[idx])
	{
		if ((*input)[idx] == '$')
		{
			if (ft_isalnum((*input)[++idx]) || (*input)[idx] == '?')
			{
				key_idx = idx;
				while (ft_isalnum((*input)[key_idx]))
					key_idx++;
				*input = change_to_env(*input, &idx, key_idx, 0);
			}
		}
		idx++;
	}
}
