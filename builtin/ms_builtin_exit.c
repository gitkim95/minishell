/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:43:14 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/22 23:09:26 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"
#include "ms_env.h"
#include "ms_utils.h"
#include "libft.h"

static int	has_many_arg(char **argv);
static int	has_non_numeric(char *str);

int	ms_builtin_exit(char **argv)
{
	char	*exit_str;
	int		exit_code;

	exit_str = argv[1];
	if (!exit_str)
		exit_code = ft_atoi(ms_get_env(MS_EXIT_CODE_KEY));
	else if (has_many_arg(argv))
	{
		ft_printf("exit: too many arguments\n");
		exit_code = 1;
	}
	else if (has_non_numeric(exit_str))
	{
		ft_printf("exit: %s: numeric argument required\n", exit_str);
		exit_code = 2;
	}
	else
		exit_code = ft_atoi(exit_str);
	ms_exit(MS_EXIT_SET);
	return (exit_code);
}

static int	has_many_arg(char **argv)
{
	return (argv[1] && argv[2]);
}

static int	has_non_numeric(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		++str;
	}
	return (0);
}
