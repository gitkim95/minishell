/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:18:52 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/16 05:27:42 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_null(char **ff)
{
	if (ff && *ff)
	{
		free(*ff);
		*ff = NULL;
	}
}

static char	*cut_lf(char **save_line)
{
	size_t	i;
	char	*read_line;
	char	*tmp;

	i = 0;
	while ((*save_line)[i] != '\n' && (*save_line)[i] != '\0')
		i++;
	tmp = *save_line;
	read_line = ft_substr(tmp, 0, i + 1);
	if (!read_line)
	{
		free(tmp);
		return (NULL);
	}
	if ((*save_line)[i] == '\0')
		*save_line = ft_strdup("");
	else
		*save_line = ft_strdup(tmp + i + 1);
	free(tmp);
	return (read_line);
}

static int	read_file(int fd, char **buf, char **save_line)
{
	int		n;
	char	*tmp;

	n = 1;
	while (!ft_strchr(*save_line, '\n') && n)
	{
		n = read(fd, *buf, BUFFER_SIZE);
		if (n == -1)
			return (n);
		(*buf)[n] = '\0';
		tmp = *save_line;
		*save_line = ft_strjoin(tmp, *buf);
		free(tmp);
		if (!*save_line)
			return (-1);
	}
	return (n);
}

static char	*take_a_line(int fd, char **buf, char **save_line)
{
	int		n;

	n = read_file(fd, buf, save_line);
	if (n == -1 || !(*save_line))
		return (NULL);
	if (n == 0 || **save_line)
		return (cut_lf(save_line));
	else
		return (ft_strdup(*save_line));
}

char	*get_next_line(int fd)
{
	static char		*save_line[1048577];
	char			*buf;
	char			*read_line;

	if (fd > 1048576 || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!save_line[fd])
		save_line[fd] = ft_strdup("");
	read_line = take_a_line(fd, &buf, &save_line[fd]);
	free_null(&buf);
	if (!read_line || !*read_line)
	{
		free(read_line);
		free_null(&save_line[fd]);
		return (NULL);
	}
	return (read_line);
}
