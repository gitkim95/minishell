/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:51:49 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/11 16:07:14 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	init_struct(char *str, t_cmd_list *list)
{
	char	**temp;

	temp = ft_split(str, '|');
	if (!temp)
	{
		//error
	}
	make_list(list, temp);
	free_split(temp);
}
