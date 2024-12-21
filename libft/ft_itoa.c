/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:03:17 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/21 20:08:51 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cal_len(long long n)
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

static void	fill_arr(long long n, char *arr, int *i)
{
	if (n >= 10)
		fill_arr(n / 10, arr, i);
	arr[(*i)++] = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	long long	conv;
	char		*result;
	int			i;
	int			res_size;

	conv = (long long)n;
	res_size = cal_len(conv);
	result = (char *)malloc(res_size + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	if (conv < 0)
	{
		conv = -conv;
		result[i] = '-';
		i++;
	}
	fill_arr(conv, result, &i);
	result[i] = '\0';
	return (result);
}
