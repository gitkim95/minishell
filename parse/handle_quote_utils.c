/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 02:15:22 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/21 22:15:14 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ms_parse.h"
#include "ms_utils.h"
#include "libft.h"

void	skip_quote(char *arg, int *idx, char quote)
{
	(*idx)++;
	while (arg[*idx] != quote && arg[*idx])
		(*idx)++;
	if (arg[*idx])
		(*idx)++;
}

char	*realloc_option(char *option, int *idx, int *quotes_idx)
{
	int		option_len;
	char	buf[MS_BUFFER_SIZE];

	option_len = ft_strlen(option);
	buf[0] = '\0';
	option[quotes_idx[0]] = '\0';
	option[quotes_idx[1]] = '\0';
	ft_strcat(buf, option);
	ft_strcat(buf, option + quotes_idx[0] + 1);
	if (quotes_idx[1] >= option_len)
		*idx -= 1;
	else
	{
		ft_strcat(buf, option + quotes_idx[1] + 1);
		*idx -= 2;
	}
	free(option);
	option = NULL;
	return (ft_strdup(buf));
}

void	set_quotes_idx(char *option, int *idx, char quote, int *quotes_idx)
{
	if (option[*idx] == quote)
	{
		quotes_idx[0] = *idx;
		(*idx)++;
		while (option[*idx] != quote && option[*idx])
			(*idx)++;
		quotes_idx[1] = *idx;
	}
}

void	delete_quotes(char **option, int *flag)
{
	int	idx;
	int	quotes_idx[2];

	idx = 0;
	while ((*option)[idx])
	{
		quotes_idx[0] = -1;
		quotes_idx[1] = -1;
		if ((*option)[idx] == '\'')
			set_quotes_idx(*option, &idx, '\'', quotes_idx);
		else if ((*option)[idx] == '\"')
			set_quotes_idx(*option, &idx, '\"', quotes_idx);
		if (quotes_idx[0] != -1 && quotes_idx[1] != -1)
		{
			*option = realloc_option(*option, &idx, quotes_idx);
			if (flag)
				*flag = 1;
		}
		idx++;
	}
}
