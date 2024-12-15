/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:43:14 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/15 20:06:39 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"
#include "ms_env.h"
#include "ms_utils.h"
#include "libft.h"

static void	print_env(char **env_arr);

int	ms_builtin_env(char **argv)
{
	char		**env_arr;

	(void) argv;
	env_arr = get_env_array();
	print_env(env_arr);
	free_split(env_arr);
	return (0);
}

static void	print_env(char **env_arr)
{
	while (*env_arr)
	{
		ft_printf("%s\n", *env_arr);
		++env_arr;
	}
}
