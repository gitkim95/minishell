/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:12:19 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/13 17:02:25 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(char arg, va_list ap)
{
	int	length;
	int	nbr;

	nbr = va_arg(ap, int);
	length = 0;
	conv_hex((unsigned int)nbr, &length, arg);
	return (length);
}

int	print_p(va_list ap)
{
	int		length;
	size_t	addr;

	addr = (size_t)va_arg(ap, void *);
	length = 0;
	conv_addr(addr, &length);
	return (length);
}
