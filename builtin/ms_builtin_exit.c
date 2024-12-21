/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:43:14 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/21 18:45:49 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"
#include "libft.h"

int	ms_builtin_exit(char **argv)
{
	char	*exit_str;
	int		exit_code;

	exit_str = argv[1];
	if (!exit_str)
		exit_code = 0;
	else
		exit_code = ft_atoi(exit_str);
	ft_printf("exit\n");
	exit(exit_code);
}
