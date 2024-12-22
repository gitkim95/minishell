/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:01:23 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/22 22:16:33 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ms_env.h"
#include "ms_utils.h"
#include "ft_hash.h"
#include "libft.h"

static int	append_node_to_array(t_hash_node *env_node, char **str_arr);
static int	is_env(char *key);

char	**get_env_array(void)
{
	int			idx;
	int			env_count;
	char		**str_arr;
	t_hash		*env_hash;
	t_hash_node	*env_node;

	idx = 0;
	env_count = 0;
	env_hash = get_env_hash();
	str_arr = (char **)ft_calloc(env_hash->size + 1, sizeof(char *));
	while (idx < FT_HASH_TABLE)
	{
		env_node = env_hash->table[idx].head;
		env_count += append_node_to_array(env_node, str_arr + env_count);
		++idx;
	}
	return (str_arr);
}

static int	append_node_to_array(t_hash_node *env_node, char **str_arr)
{
	int		env_count;
	int		env_len;
	char	*env_str;

	env_count = 0;
	while (env_node)
	{
		if (is_env(env_node->key))
		{
			env_len = ft_strlen(env_node->key) + ft_strlen(env_node->s_value);
			env_str = (char *)ft_calloc(env_len + 2, sizeof(char *));
			ft_strcat(env_str, env_node->key);
			ft_strcat(env_str, "=");
			ft_strcat(env_str, env_node->s_value);
			*(str_arr + env_count) = env_str;
			++env_count;
		}
		env_node = env_node->next;
	}
	return (env_count);
}

static int	is_env(char *key)
{
	if (ft_strcmp(key, MS_EXIT_CODE_KEY) == 0)
		return (0);
	else if (ft_strcmp(key, MS_IFS_KEY) == 0)
		return (0);
	return (1);
}
