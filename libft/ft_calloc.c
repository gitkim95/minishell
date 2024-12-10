/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:36:03 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/05 23:35:52 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	mem_size;
	char	*new_str;

	if (size && nmemb > UINT_MAX / size)
		return (NULL);
	mem_size = size * nmemb;
	new_str = (char *)malloc(sizeof(char) * mem_size);
	if (new_str == NULL)
		return (NULL);
	ft_memset(new_str, 0, mem_size);
	return (new_str);
}
