/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 01:41:56 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/07 12:08:05 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_alloc(char **res, int idx)
{
	int	i;

	i = 0;
	if (res)
	{
		while (i < idx)
		{
			free(res[i]);
			i++;
		}
		free(res);
	}
}

int	count_words(char const *s, char c)
{
	int	i;
	int	cnt;

	if (!s)
		return (0);
	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0)
		{
			if (!(s[i] == c || s[i] == '\0'))
				cnt++;
		}
		else
		{
			if (!(s[i] == c || s[i] == '\0') && (s[i - 1] == c))
				cnt++;
		}
		i++;
	}
	return (cnt);
}

void	insert_split(char const *s, char c, char *res_split)
{
	int	i;

	i = 0;
	while (!(s[i] == c || s[i] == '\0'))
	{
		res_split[i] = s[i];
		i++;
	}
	res_split[i] = '\0';
}

void	alloc_split(char const *s, char c, char **res_split)
{
	int	i;
	int	j;
	int	res_idx;

	res_idx = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] == c || s[i] == '\0'))
		{
			i++;
			continue ;
		}
		j = 0;
		while (!(s[i + j] == c || s[i + j] == '\0'))
			j++;
		res_split[res_idx] = (char *)malloc(sizeof(char) * (j + 1));
		if (res_split[res_idx] == NULL)
		{
			free_alloc(res_split, res_idx);
			return ;
		}
		insert_split(s + i, c, res_split[res_idx++]);
		i += j;
	}
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**res_split;

	words = count_words(s, c);
	res_split = (char **)malloc(sizeof(char *) * (words + 1));
	if (res_split == NULL)
		return (NULL);
	res_split[words] = 0;
	if (!words)
		return (res_split);
	alloc_split(s, c, res_split);
	return (res_split);
}
