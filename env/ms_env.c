/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:01:23 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/13 15:58:53 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ms_env.h"
#include "ft_hash.h"
#include "libft.h"

static t_hash	**get_env_state(void);

t_hash	*get_env_hash(void)
{
	t_hash	**env_hash;

	env_hash = get_env_state();
	return (*env_hash);
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
