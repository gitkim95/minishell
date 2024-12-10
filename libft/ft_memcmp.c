/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:12:46 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/07 03:54:12 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str_1;
	unsigned char	*str_2;

	if (!s1 || !s2)
		return (0);
	str_1 = (unsigned char *)s1;
	str_2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*str_1 != *str_2)
			return (*str_1 - *str_2);
		i++;
		str_1++;
		str_2++;
	}
	return (0);
}
