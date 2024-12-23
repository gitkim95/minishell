/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:58:53 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/23 18:30:26 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ms_parse.h"
#include "ms_utils.h"
#include "libft.h"

char	**get_path(char *path)
{
	char	**path_split;

	path_split = ft_split(path, ':');
	if (!path_split)
		exit(ENOMEM);
	return (path_split);
}

char	*parse_cmd_path(char *cmd, char **path)
{
	char	buf[MS_BUFFER_SIZE];

	if (!cmd)
		return (cmd);
	if (*cmd == '/' || *cmd == '\0')
		return (cmd);
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
