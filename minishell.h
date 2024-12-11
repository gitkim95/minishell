/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:12:29 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/11 16:06:50 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MS_BUFFER_SIZE 1024

typedef struct s_cmd
{
	char			**av;
	char			*s_input;
	char			*s_output;
	char			*d_input;
	char			*d_output;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_cmd_list
{
	t_cmd	*head;
	t_cmd	*tail;
	int		size;
}	t_cmd_list;

//check_redirection_sign_1.c
char	*get_redirection_target(char *cmd_str);
int		is_double_input(char *cmd_str, t_cmd *node);
int		is_single_input(char *cmd_str, t_cmd *node);
int		is_double_output(char *cmd_str, t_cmd *node);
int		is_single_output(char *cmd_str, t_cmd *node);

//check_redirection_sign_2.c
void	check_input_redirection_sign(char *cmd_str, t_cmd *node);
void	check_output_redirection_sign(char *cmd_str, t_cmd *node);

//ms_init_cmd.c
void	init_struct(char *str, t_cmd_list *list);

//ms_make_list.c
t_cmd	*make_new_node(char *cmd_str, char **path);
void	list_add_back(t_cmd_list *list, t_cmd *node);
void	make_list(t_cmd_list *list, char **cmd_split);

//ms_mem_free.c
void	free_split(char **split);

//ms_parse_path.c
char	**get_path(char *path);
char	**append_cmd_options(char *arg);
char	*parse_cmd_path(char *cmd, char **path);

//ms_utils.c
char	*ft_strcat(char *dest, const char *src);

#endif