/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:35:59 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/07 03:57:34 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ch_dst;
	unsigned char	*ch_src;

	if (!src || !dest)
		return (NULL);
	ch_src = (unsigned char *)src;
	ch_dst = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		ch_dst[i] = ch_src[i];
		i++;
	}
	return (dest);
}
