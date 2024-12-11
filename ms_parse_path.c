/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:58:53 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/11 16:00:01 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "libft.h"

char	**get_path(char *path)
{
	char	**path_split;

	path_split = ft_split(path, ':');
	if (!path)
	{
		//error
	}
	return (path_split);
}

char	**append_cmd_options(char *arg)
{
	int		idx;
	char	**argv;
	char	buf[MS_BUFFER_SIZE];

	argv = ft_split(arg, ' ');
	if (!argv)
		return (NULL);
	if (!argv[1] || !ft_strchr(argv[1], '\''))
		return (argv);
	buf[0] = '\0';
	idx = 1;
	while (argv[idx])
	{
		ft_strcat(buf, argv[idx]);
		ft_strcat(buf, " ");
		free(argv[idx]);
		argv[idx++] = NULL;
	}
	argv[1] = ft_strtrim(buf, " \'\"");
	return (argv);
}

char	*parse_cmd_path(char *cmd, char **path)
{
	char	buf[MS_BUFFER_SIZE];

	while (*path)
	{
		buf[0] = '\0';
		ft_strcat(buf, *path);
		ft_strcat(buf, "/");
		ft_strcat(buf, cmd);
		if (access(buf, X_OK) == 0)
		{
			free(cmd);
			return (ft_strdup(buf));
		}
		++path;
	}
	return (cmd);
}
