/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote_mark.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:40:32 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/21 02:37:34 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parse.h"
#include "libft.h"

static int	get_argv_count(char *arg, int *stock_idx, int *idx)
{
	int	cnt;

	cnt = 1;
	while (arg[*idx])
	{
		if (arg[*idx] == '\'')
			skip_quote(arg, idx, '\'');
		else if (arg[*idx] == '\"')
			skip_quote(arg, idx, '\"');
		else if (arg[*idx] == ' ')
		{
			if (arg[*idx + 1] != ' ' && arg[*idx + 1])
			{
				stock_idx[cnt - 1] = *idx;
				cnt++;
			}
			(*idx)++;
		}
		else
			(*idx)++;
	}
	stock_idx[cnt - 1] = *idx;
	return (cnt);
}

static void	get_options(char *arg, char **argv, int *stock_idx, int argv_size)
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

static void	refine_option(char **option)
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

	idx = 0;
	while (arg[idx] == ' ')
		idx++;
	ft_memset(stock_idx, -1, sizeof(int) * 100);
	argv_size = get_argv_count(arg, stock_idx, &idx);
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
