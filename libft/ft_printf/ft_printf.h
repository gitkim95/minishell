/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:21:34 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/13 18:23:23 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# define TYPES "cspdiuxX%"
# define LOWCASE "0123456789abcdef"
# define UPCASE "0123456789ABCDEF"

int		ft_printchar(char c);
int		ft_printstr(char *s);
void	conv_hex(unsigned int nbr, int *cnt, char arg);
void	conv_addr(size_t nbr, int *cnt);
int		parsing_type(char arg, va_list ap);
int		ft_printf(const char *str, ...);
int		print_c_p(char arg, va_list ap);
int		print_s(va_list ap);
int		print_d_i(va_list ap);
int		print_u(va_list ap);
int		print_hex(char arg, va_list ap);
int		print_p(va_list ap);
char	*ft_itoa_ll(long long nbr);

#endif