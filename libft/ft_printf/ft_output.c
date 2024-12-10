/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:21:17 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/13 17:02:17 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	return (i);
}

void	conv_hex(unsigned int nbr, int *cnt, char arg)
{
	if (nbr >= 16)
		conv_hex(nbr / 16, cnt, arg);
	if (arg == 'x')
		*cnt += ft_printchar(LOWCASE[nbr % 16]);
	else
		*cnt += ft_printchar(UPCASE[nbr % 16]);
}

void	conv_addr(size_t nbr, int *cnt)
{
	if (nbr == 0)
	{
		*cnt += ft_printstr("(nil)");
		return ;
	}
	if (*cnt == 0)
		*cnt += ft_printstr("0x");
	if (nbr >= 16)
		conv_addr(nbr / 16, cnt);
	*cnt += ft_printchar(LOWCASE[nbr % 16]);
}
