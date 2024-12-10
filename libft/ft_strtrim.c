/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 23:24:13 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/09 18:36:51 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	trim_paste(char const *s1, char *result, size_t offset)
{
	size_t	i;

	i = 0;
	while (*s1 && i < offset)
	{
		result[i] = *s1;
		i++;
		s1++;
	}
	result[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*result;
	size_t		front;
	size_t		back;

	front = 0;
	back = ft_strlen(s1);
	while (ft_strchr(set, s1[front]) && front < back)
		front++;
	while (ft_strchr(set, s1[back - 1]) && front < back)
		back--;
	result = (char *)malloc(back - front + 1);
	if (result == NULL)
		return (NULL);
	trim_paste(s1 + front, result, back - front);
	return (result);
}
