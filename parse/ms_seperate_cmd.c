/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_seperate_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:12:33 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/23 17:02:13 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parse.h"
#include "libft.h"

static int	count_pipe(int *pipe_idx)
{
	int	count;
	int	idx;

	count = 0;
	idx = 0;
	while (idx < MS_BUFFER_SIZE)
	{
		if (pipe_idx[idx] == -1)
			break ;
		count++;
		idx++;
	}
	return (count);
}

static void	get_pipe_idx(char *input, int *pipe_idx)
{
	int	idx;
	int	arr_idx;

	arr_idx = 0;
	idx = 0;
	while (input[idx])
	{
		if (input[idx] == '\'')
			skip_quote(input, &idx, '\'');
		else if (input[idx] == '\"')
			skip_quote(input, &idx, '\"');
		else if (input[idx] == '|')
		{
			pipe_idx[arr_idx] = idx;
			arr_idx++;
			idx++;
		}
		else
			idx++;
	}
}

static void	init_pipe_idx_arr(int *pipe_idx)
{
	int	idx;

	idx = 0;
	while (idx < MS_BUFFER_SIZE)
	{
		pipe_idx[idx] = -1;
		idx++;
	}
}

static void	supply_sep_cmd(char **sep_cmd, char *input, int *p_idx, int p_num)
{
	int	idx;

	idx = 0;
	while (idx < p_num + 1)
	{
		if (p_num == 0)
			sep_cmd[idx] = ft_strdup(input);
		else if (idx == p_num)
			sep_cmd[idx] = ft_strdup(input + p_idx[idx - 1] + 1);
		else if (idx == 0)
			sep_cmd[idx] = ft_substr(input, 0, p_idx[idx]);
		else
			sep_cmd[idx] = ft_substr(input, p_idx[idx - 1] + 1, \
									p_idx[idx] - p_idx[idx - 1] - 1);
		idx++;
	}
}

char	**seperate_by_pipe(char *input)
{
	char	**sep_cmd;
	int		pipe_idx[MS_BUFFER_SIZE];
	int		pipe_num;

	init_pipe_idx_arr(pipe_idx);
	get_pipe_idx(input, pipe_idx);
	pipe_num = count_pipe(pipe_idx);
	sep_cmd = (char **)ft_calloc(pipe_num + 2, sizeof(char *));
	if (!sep_cmd)
		exit(ENOMEM);
	supply_sep_cmd(sep_cmd, input, pipe_idx, pipe_num);
	return (sep_cmd);
}
