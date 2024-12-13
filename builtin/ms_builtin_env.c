/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:43:14 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/13 17:00:03 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"
#include "ms_env.h"
#include "libft.h"
#include "ft_hash.h"

static void	print_env(t_hash_node *env_node);

int	ms_builtin_env(char **argv)
{
	int			idx;
	t_hash		*env_hash;
	t_hash_node	*env_node;

	(void) argv;
	idx = 0;
	env_hash = get_env_hash();
	while (idx < FT_HASH_TABLE)
	{
		env_node = env_hash->table[idx].head;
		print_env(env_node);
		++idx;
	}
	return (0);
}

static void	print_env(t_hash_node *env_node)
{
	while (env_node)
	{
		ft_printf("%s=%s\n", env_node->key, env_node->s_value);
		env_node = env_node->next;
	}
}
