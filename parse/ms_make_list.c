/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:56:36 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/19 18:41:38 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ms_parse.h"
#include "ms_env.h"
#include "ms_builtin.h"
#include "ms_utils.h"
#include "libft.h"

static t_cmd	*make_new_node(char *cmd_str, char **path)
{
	char	**cmd_split;
	t_cmd	*new_node;

	new_node = (t_cmd *)ft_calloc(sizeof(t_cmd), 1);
	if (!new_node)
		exit(ENOMEM);
	set_cmd_struct_zero(new_node);
	output_redirection_sign(cmd_str, new_node);
	input_redirection_sign(cmd_str, new_node);
	set_isspace_to_blank(cmd_str);
	cmd_split = append_cmd_options(cmd_str);
	if (!cmd_split)
		exit(ENOMEM);
	if (!is_builtin(cmd_split[0]))
		cmd_split[0] = parse_cmd_path(cmd_split[0], path);
	if (!cmd_split)
		exit(ENOMEM);
	new_node->av = cmd_split;
	return (new_node);
}

static void	list_add_back(t_cmd_list *list, t_cmd *node)
{
	if (!list->head)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->next = node;
		node->prev = list->tail;
		list->tail = node;
	}
	list->size++;
}

void	make_list(t_cmd_list *list, char **cmd_split)
{
	int		i;
	char	**path;
	t_cmd	*node;

	path = get_path(ms_get_env("PATH"));
	i = 0;
	set_list_struct_zero(list);
	while (cmd_split[i])
	{
		node = make_new_node(cmd_split[i], path);
		if (!node)
			exit(ENOMEM);
		list_add_back(list, node);
		i++;
	}
	free_split(path);
}

char	*change_to_env(char *cmd_str, int *idx, int find_key)
{
	char	*env_key;
	char	*env_value;
	char	*new_cmd_str;

	env_key = ft_substr(cmd_str, *idx + 1, len - find_key);
	env_value = ms_get_env(env_key);
	if (env_value)
	{
		new_cmd_str = ft_substr(cmd_str, 0, find_key - 1)
	}
	else
	{

	}
	free(env_key);
	free(cmd_str);
	return (new_cmd_str);
}

char	*handle_env_sign(char **cmd_str)
{
	int		i;
	int		find_key;
	char	*env_key;
	char	*new_cmd_str;

	i = 0;
	while (*cmd_str[i])
	{
		if (cmd_str[i] == '\'')
		{
			i++;
			while (cmd_str[i] != '\'' || cmd_str[i] != '\0')
				i++;
		}
		else if (cmd_str[i] == '$')
		{
			if (cmd_str[++i] != ' ' || cmd_str[i] != '\0')
			{
				find_key = i + 1;
				while (cmd_str[find_key] != ' ' || cmd_str[find_key] != '\0')
					find_key++;
				*cmd_str = change_to_env(cmd_str, &i, find_key);
			}
		}
	}
}
