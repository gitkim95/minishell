/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:12:21 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/11 15:24:59 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

char	**get_path(char *path)
{
	char	**path;

	path = ft_split(path, ":");\
	if (!path)
	{
		//error
	}
	return (path);
}

static char	**append_cmd_options(char *arg)
{
	int		idx;
	char	**argv;
	char	buf[MS_BUFFER_SIZE];

	argv = ft_split(arg, ' ');
	if (!argv)
		return (NULL);
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
	return (argv);
}

char	*parse_cmd_path(char *cmd, char **path)
{
	char	buf[MS_BUFFER_SIZE];

	while (*path)
	{
		buf[0] = '\0';
		ft_strcat(buf, *path);
		ft_strcat(buf, "/");
		ft_strcat(buf, cmd);
		if (access(buf, X_OK) == 0)
		{
			free(cmd);
			return (ft_strdup(buf));
		}
		++path;
	}
	return (cmd);
}

void	check_input_redirection_sign(char *cmd_str, t_cmd *node)
{
	int	loc;
	
	loc = is_double_input(cmd_str, node);
	if (loc)
		return ;
	loc = is_single_input(cmd_str, node);
	if (loc)
		return ;
}

void	check_output_redirection_sign(char *cmd_str, t_cmd *node)
{
	int	loc;
	
	loc = is_double_output(cmd_str, node);
	if (loc)
		return ;
	loc = is_single_output(cmd_str, node);
	if (loc)
		return ;
}

t_cmd	*make_new_node(char *cmd_str, char **path)
{
	char	**cmd_split;
	t_cmd	*new_node;

	cmd_split = append_cmd_options(cmd_str);
	if (!cmd_split)
	{
		//error;
	}
	new_node = (t_cmd *)ft_calloc(sizeof(t_cmd), 1);
	if (!new_node)
	{
		//error;
	}
	check_output_redirection_sign(cmd_str, new_node);
	check_input_redirection_sign(cmd_str, new_node);
	cmd_split[0] = parse_cmd_path(cmd_split[0], path);
	if (!cmd_split)
	{
		//error
	}
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
		list->tail = node;
	}
	list->size++;
}




void	make_list(t_cmd_list *list, char **cmd_split)
{
	int		i;
	char	**path;
	t_cmd	*node;

	path = get_path;
	i = 0;
	ft_memset(list, 0, sizeof(t_cmd_list));
	while (cmd_split[i])
	{
		node = make_new_node(cmd_split[i], path);
		if (!node)
		{
			//error;
		}
		list_add_back(list, node);
		i++;
	}
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	init_struct(char *str, t_cmd_list *list)
{
	char **temp;

	temp = ft_split(str, "|");
	if (!temp)
	{
		//error
	}
	make_list(list, temp);
	free_split(temp);
}

void	execute_cmd(t_cmd_list *list)
{

}

int	main()
{
	char 		*str;
	t_cmd_list	list;
	
	while (1)
	{
		str = readline("$ ");
		if (str)
		{
			init_struct(str, &list);
			free(str);
			execute_cmd(&list);
		}
		else
			break;
		add_history(str);
		free(str);
	}
	return (0);
}