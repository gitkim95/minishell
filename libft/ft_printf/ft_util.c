/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:49:12 by gitkim            #+#    #+#             */
/*   Updated: 2024/10/13 17:02:31 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cal_len(long long n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		cnt++;
	}
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

void	fill_arr(long long n, char *arr, int *i)
{
	if (n >= 10)
		fill_arr(n / 10, arr, i);
	arr[(*i)++] = n % 10 + '0';
}

char	*ft_itoa_ll(long long nbr)
{
	char		*result;
	int			i;
	int			res_size;

	res_size = cal_len(nbr);
	result = (char *)malloc(res_size + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		result[i] = '-';
		i++;
	}
	fill_arr(nbr, result, &i);
	result[i] = '\0';
	return (result);
}
