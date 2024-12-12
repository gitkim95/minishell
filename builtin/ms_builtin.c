/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:22:49 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/12 15:47:47 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ms_builtin.h"

static int	ft_strcmp(char *s1, char *s2);

char	**get_builtin_cmd(void)
{
	static char	**builtin_cmd = {
		"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL
	};

	return (builtin_cmd);
}

int	is_builtin(char *cmd)
{
	char	**builtin_cmd;

	builtin_cmd = get_builtin_cmd();
	while (*builtin_cmd)
	{
		if (ft_strcmp(*builtin_cmd, cmd) == 0)
			return (1);
		++builtin_cmd;
	}
	return (0);
}

static int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	c1;
	unsigned char	c2;
	unsigned int	idx;

	idx = 0;
	while (s1[idx] != '\0' && s2[idx] != '\0')
	{
		c1 = s1[idx];
		c2 = s2[idx];
		if (c1 != c2)
			return (c1 - c2);
		++idx;
	}
	c1 = s1[idx];
	c2 = s2[idx];
	return (c1 - c2);
}
