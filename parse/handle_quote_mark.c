/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote_mark.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:40:32 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/20 17:37:57 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ms_utils.h"
#include "libft.h"
#include "ms_parse.h"

void	skip_quote(char *arg, int *idx, char quote)
{
	while (arg[*idx] != quote && arg[*idx])
		(*idx)++;
}

int	get_argv_count(char *arg)
{
	int	idx;
	int	cnt;

	cnt = 0;
	idx = 0;
	while (arg[idx])
	{
		if (arg[idx] == '\'')
			skip_quote(arg, &idx, '\'');
		else if (arg[idx] == '\"')
		{

		}
		idx++;
	}
	return (cnt);
}

char	**append_cmd_options(char *arg)
{
	int		idx;
	char	**argv;
	char	buf[MS_BUFFER_SIZE];

	argv = ft_split(arg, ' ');
	if (!argv)
		exit(ENOMEM);
	if (!argv[1] || !ft_strchr(argv[1], '\''))
		return (argv);
	buf[0] = '\0';
	idx = 1;
	while (argv[idx])
	{
		ft_strcat(buf, argv[idx]);
		ft_strcat(buf, " ");
		free(argv[idx]);
		argv[idx++] = NULL;
	}
	argv[1] = ft_strtrim(buf, " \'\"");
	if (!argv[1])
		exit(ENOMEM);
	return (argv);
}