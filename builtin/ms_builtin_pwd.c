/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:43:14 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/13 17:04:45 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"
#include "ms_env.h"
#include "libft.h"

int	ms_builtin_pwd(char **argv)
{
	(void) argv;
	ft_printf("%s\n", ms_get_env("PWD"));
	return (0);
}
