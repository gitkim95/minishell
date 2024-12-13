/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:56:36 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/13 20:21:01 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ms_parse.h"
#include "ms_env.h"
#include "libft.h"

t_cmd	*make_new_node(char *cmd_str, char **path)
{
	char	**cmd_split;
	t_cmd	*new_node;

	new_node = (t_cmd *)ft_calloc(sizeof(t_cmd), 1);
	if (!new_node)
		exit(ENOMEM);
	set_cmd_struct_zero(new_node);
	output_redirection_sign(cmd_str, new_node);
	input_redirection_sign(cmd_str, new_node);
	cmd_split = append_cmd_options(cmd_str);
	if (!cmd_split)
		exit(ENOMEM);
	cmd_split[0] = parse_cmd_path(cmd_split[0], path);
	if (!cmd_split)
		exit(ENOMEM);
	new_node->av = cmd_split;
	cmd_str = NULL;
	return (new_node);
}

void	list_add_back(t_cmd_list *list, t_cmd *node)
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
}
