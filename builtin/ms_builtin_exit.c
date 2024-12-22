/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:43:14 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/22 16:26:20 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"
#include "ms_env.h"
#include "ms_utils.h"
#include "libft.h"

int	ms_builtin_exit(char **argv)
{
	char	*exit_str;
	int		exit_code;

	exit_str = argv[1];
	if (!exit_str)
		exit_code = ft_atoi(ms_get_env("$?"));
	else
		exit_code = ft_atoi(exit_str);
	ms_exit(MS_EXIT_SET);
	return (exit_code);
}
