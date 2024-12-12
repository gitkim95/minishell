/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:22:49 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/12 19:58:23 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_hash.h"
#include "ms_builtin.h"

t_hash	*get_builtin_hash(void)
{
	static t_hash	*builtin = NULL;

	if (!builtin)
	{
		builtin = make_hash(FT_HASH_INT);
		put_hash_value_int(builtin, "echo", MS_ECHO);
		put_hash_value_int(builtin, "cd", MS_CD);
		put_hash_value_int(builtin, "pwd", MS_PWD);
		put_hash_value_int(builtin, "export", MS_EXPORT);
		put_hash_value_int(builtin, "unset", MS_UNSET);
		put_hash_value_int(builtin, "env", MS_ENV);
		put_hash_value_int(builtin, "exit", MS_EXIT);
	}
	return (builtin);
}

int	is_builtin(char *cmd)
{
	t_hash	*builtin_hash;

	builtin_hash = get_builtin_hash();
	return (get_hash_node(builtin_hash, cmd) != NULL);
}

int	exec_builtin(char **argv)
{
	t_hash		*builtin_hash;
	t_builtin	builtin_type;

	builtin_hash = get_builtin_hash();
	builtin_type = get_hash_node(builtin_hash, argv[0])->i_value;
	if (builtin_type == MS_ECHO)
		return (ms_builtin_echo(argv));
	if (builtin_type == MS_CD)
		return (ms_builtin_cd(argv));
	if (builtin_type == MS_PWD)
		return (0);
	if (builtin_type == MS_EXPORT)
		return (0);
	if (builtin_type == MS_UNSET)
		return (0);
	if (builtin_type == MS_ENV)
		return (0);
	if (builtin_type == MS_EXIT)
		return (0);
	exit(1);
}
