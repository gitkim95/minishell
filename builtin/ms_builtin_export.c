/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:43:14 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/13 17:01:52 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"
#include "ms_env.h"
#include "libft.h"

/* todo: multi arg input */
int	ms_builtin_export(char **argv)
{
	char	*env;
	char	*delimiter;

	env = argv[1];
	if (!env)
		return (0);
	delimiter = ft_strchr(env, '=');
	if (!delimiter)
		return (0);
	*delimiter = '\0';
	ms_set_env(env, delimiter + 1);
	return (0);
}
