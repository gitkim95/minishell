/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:01:38 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/08 18:51:14 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	s_len;

	if (!s || !f)
		return ;
	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len)
	{
		(*f)(i, &s[i]);
		i++;
	}
}
