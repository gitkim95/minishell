/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:05:58 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/14 21:35:02 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_PARSE_H
# define MS_PARSE_H

# include "ms_struct.h"

//check_redirection_sign.c
void	input_redirection_sign(char *cmd_str, t_cmd *node);
void	output_redirection_sign(char *cmd_str, t_cmd *node);

//check_redirection_target.c
char	*get_redirection_target(char *cmd_str);
int		is_double_input(char *cmd_str);
int		is_single_input(char *cmd_str);
int		is_double_output(char *cmd_str);
int		is_single_output(char *cmd_str);

//ms_init_cmd.c
void	set_isspace_to_blank(char *cmd);
void	set_list_struct_zero(t_cmd_list *list);
void	set_cmd_struct_zero(t_cmd *cmd);
void	init_struct(char *str, t_cmd_list *list);

//ms_make_list.c
t_cmd	*make_new_node(char *cmd_str, char **path);
void	list_add_back(t_cmd_list *list, t_cmd *node);
void	make_list(t_cmd_list *list, char **cmd_split);

//ms_open_fd.c
void	set_eof(char *target, t_cmd *node);
void	set_single_input_fd(char *target, t_cmd *node);
void	set_single_output_fd(char *target, t_cmd *node);
void	set_double_output_fd(char *target, t_cmd *node);

//ms_parse_path.c
char	**get_path(char *path);
char	**append_cmd_options(char *arg);
char	*parse_cmd_path(char *cmd, char **path);

#endif