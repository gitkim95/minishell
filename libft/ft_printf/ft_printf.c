/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:05:18 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/13 18:23:19 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

int	parsing_type(char arg, va_list ap)
{
	int		length;

	if (ft_strchr(TYPES, arg))
	{
		if (arg == 'c' || arg == '%')
			length = print_c_p(arg, ap);
		if (arg == 's')
			length = print_s(ap);
		if (arg == 'u')
			length = print_u(ap);
		if (arg == 'd' || arg == 'i')
			length = print_d_i(ap);
		if (arg == 'X' || arg == 'x')
			length = print_hex(arg, ap);
		if (arg == 'p')
			length = print_p(ap);
	}
	else
		return (-1);
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		ret_len;
	int		tmp;

	va_start(ap, str);
	ret_len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (*++str)
			{
				tmp = parsing_type((char)*str, ap);
				if (tmp == -1)
					return (-1);
				ret_len += tmp;
			}
		}
		else
			ret_len += ft_printchar(*str);
		str++;
	}
	va_end(ap);
	return (ret_len);
}
