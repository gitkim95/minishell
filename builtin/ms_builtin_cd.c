/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:43:14 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/12 20:49:14 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ms_builtin.h"

int	ms_builtin_cd(char **argv)
{
	char	*path;
	int		result;

	if (argv[1])
		path = argv[1];
	else
		path = "/home/hwilkim";
	result = chdir(path);
	if (result)
		perror("minishell");
	return (result != 0);
}
