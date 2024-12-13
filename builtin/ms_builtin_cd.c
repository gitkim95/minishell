/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:43:14 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/13 16:09:41 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ms_builtin.h"
#include "ms_env.h"

static void	update_pwd_env(void);

int	ms_builtin_cd(char **argv)
{
	char	*path;
	int		error;

	if (argv[1])
		path = argv[1];
	else
		path = ms_get_env("HOME");
	error = chdir(path);
	if (error)
		perror("minishell");
	else
		update_pwd_env();
	return (error != 0);
}

static void	update_pwd_env(void)
{
	char	*pwd;
	char	*prev_pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return ;
	prev_pwd = ms_get_env("PWD");
	ms_set_env("OLDPWD", prev_pwd);
	ms_set_env("PWD", pwd);
	free(pwd);
}
