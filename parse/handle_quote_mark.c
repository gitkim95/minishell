/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote_mark.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:40:32 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/20 22:24:56 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ms_parse.h"
#include "ms_utils.h"
#include "libft.h"

void	skip_quote(char *arg, int *idx, char quote)
{
	while (arg[*idx] != quote && arg[*idx])
		(*idx)++;
}

int	get_argv_count(char *arg, int *stock_idx)
{
	int	idx;
	int	cnt;

	cnt = 1;
	idx = 0;
	while (arg[idx])
	{
		if (arg[idx] == '\'')
			skip_quote(arg, &idx, '\'');
		else if (arg[idx] == '\"')
			skip_quote(arg, &idx, '\"');
		else if (arg[idx] == ' ')
		{
			if (arg[idx + 1] != ' ' && arg[idx + 1])
			{
				stock_idx[cnt - 1] = idx;
				cnt++;
			}
		}
		idx++;
	}
	stock_idx[cnt - 1] = idx;
	return (cnt);
}

void	get_options(char *arg, char **argv, int *stock_idx, int argv_size)
{
	int		idx;
	int		argv_idx;

	argv_idx = 0;
	idx = 0;
	while (argv_idx < argv_size)
	{
		argv[argv_idx] = ft_substr(arg, idx, stock_idx[argv_idx] - idx);
		if (!argv[argv_idx])
			exit(ENOMEM);
		idx = stock_idx[argv_idx] + 1;
		argv_idx++;
	}
}

char	*realloc_option(char *option, int *idx, int *quotes_idx)
{
	char	buf[MS_BUFFER_SIZE];

	buf[0] = '\0';
	option[quotes_idx[0]] = '\0';
	option[quotes_idx[1]] = '\0';
	ft_strcat(buf, option);
	ft_strcat(buf, option + quotes_idx[0] + 1);
	ft_strcat(buf, option + quotes_idx[1] + 1);
	free(option);
	*idx -= 2;
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

void	delete_quotes(char **option)
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
			*option = realloc_option(*option, &idx, quotes_idx);
		idx++;
	}
}

void	refine_option(char **option)
{
	char	*temp;

	temp = *option;
	*option = ft_strtrim(*option, " ");
	free(temp);
	delete_quotes(option);
}

char	**append_cmd_options(char *arg)
{
	int		idx;
	int		argv_size;
	int		stock_idx[100];
	char	**argv;

	ft_memset(stock_idx, -1, sizeof(int) * 100);
	argv_size = get_argv_count(arg, stock_idx);
	argv = (char **)ft_calloc(argv_size + 1, sizeof(char *));
	if (!argv)
		exit(ENOMEM);
	get_options(arg, argv, stock_idx, argv_size);
	idx = 0;
	while (idx < argv_size)
	{
		refine_option(&argv[idx]);
		idx++;
	}
	return (argv);
}
