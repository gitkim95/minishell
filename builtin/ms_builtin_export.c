/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:43:14 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/22 22:46:53 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"
#include "ms_env.h"
#include "libft.h"

int	ms_builtin_export(char **argv)
{
	int		i;
	char	*delimiter;

	i = 1;
	while (argv[i])
	{
		delimiter = ft_strchr(argv[i], '=');
		if (delimiter)
		{
			*delimiter = '\0';
			ms_set_env(argv[i], delimiter + 1);
		}
		++i;
	}
	return (0);
}
