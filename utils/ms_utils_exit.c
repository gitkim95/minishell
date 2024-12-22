/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:13:32 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/22 16:22:43 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include "ms_utils.h"

int	ms_exit_status(int exit_status)
{
	if (WIFEXITED(exit_status))
		return (WEXITSTATUS(exit_status));
	else if (WIFSIGNALED(exit_status))
	{
		write(STDOUT_FILENO, "\n", 1);
		return (128 + WTERMSIG(exit_status));
	}
	return (exit_status);
}

int	ms_exit(int flag)
{
	static int	exit_flag = 1;

	if (flag)
		exit_flag = 0;
	return (exit_flag);
}
