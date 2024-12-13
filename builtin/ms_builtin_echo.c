/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:43:14 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/12 19:39:48 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"
#include "ms_utils.h"
#include "libft.h"

int	ms_builtin_echo(char **argv)
{
	int	new_line;
	int	idx;

	new_line = !(argv[1] && ft_strcmp(argv[1], "-n") == 0);
	if (new_line)
		idx = 1;
	else
		idx = 2;
	while (argv[idx])
	{
		ft_printf("%s", argv[idx]);
		++idx;
		if (argv[idx])
			ft_printf(" ");
	}
	if (new_line)
		ft_printf("\n");
	return (0);
}
