/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:39:35 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/23 17:59:26 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "ms_utils.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	ft_isempty(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (!ft_isblank(str[idx]))
			return (0);
		idx++;
	}
	return (1);
}

int	ft_isblank(char c)
{
	return (c == ' ' || c == '\t');
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	c1;
	unsigned char	c2;
	unsigned int	idx;

	idx = 0;
	while (s1[idx] != '\0' && s2[idx] != '\0')
	{
		c1 = s1[idx];
		c2 = s2[idx];
		if (c1 != c2)
			return (c1 - c2);
		++idx;
	}
	c1 = s1[idx];
	c2 = s2[idx];
	return (c1 - c2);
}
