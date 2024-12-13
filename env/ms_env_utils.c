/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:01:23 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/13 17:05:10 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ms_env.h"
#include "ft_hash.h"

char	*ms_get_env(char *key)
{
	t_hash		*env_hash;
	t_hash_node	*env;

	if (*key == '$')
		++key;
	env_hash = get_env_hash();
	env = get_hash_node(env_hash, key);
	if (env)
		return (env->s_value);
	return (NULL);
}

void	ms_set_env(char *key, char *value)
{
	t_hash		*env_hash;

	if (*key == '$')
		++key;
	env_hash = get_env_hash();
	put_hash_value(env_hash, key, value);
}

void	ms_del_env(char *key)
{
	t_hash		*env_hash;

	if (*key == '$')
		++key;
	env_hash = get_env_hash();
	remove_hash_value(env_hash, key);
}
