/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:01:23 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/15 20:06:43 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ms_env.h"
#include "ms_utils.h"
#include "ft_hash.h"
#include "libft.h"

static t_hash	**get_env_state(void);
static int		append_node_to_array(t_hash_node *env_node, char **str_arr);

t_hash	*get_env_hash(void)
{
	t_hash	**env_hash;

	env_hash = get_env_state();
	return (*env_hash);
}

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

void	set_env_state(char *envp[])
{
	t_hash	**env_hash;
	char	*delimiter;

	env_hash = get_env_state();
	if (*env_hash)
		return ;
	*env_hash = make_hash(FT_HASH_STR);
	while (*envp)
	{
		delimiter = ft_strchr(*envp, '=');
		*delimiter = '\0';
		put_hash_value(*env_hash, *envp, delimiter + 1);
		++envp;
	}
}

static t_hash	**get_env_state(void)
{
	static t_hash	*env_hash = NULL;

	return (&env_hash);
}

static int	append_node_to_array(t_hash_node *env_node, char **str_arr)
{
	int		env_count;
	int		env_len;
	char	*env_str;

	env_count = 0;
	while (env_node)
	{
		env_len = ft_strlen(env_node->key) + ft_strlen(env_node->s_value) + 2;
		env_str = (char *)ft_calloc(env_len, sizeof(char *));
		ft_strcat(env_str, env_node->key);
		ft_strcat(env_str, "=");
		ft_strcat(env_str, env_node->s_value);
		*(str_arr + env_count) = env_str;
		++env_count;
		env_node = env_node->next;
	}
	return (env_count);
}
