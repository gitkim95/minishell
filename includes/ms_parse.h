/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:05:58 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/23 16:55:39 by gitkim           ###   ########.fr       */
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

//handle_env_sign.c
void	handle_env_sign(char **cmd_str);
void	handle_heredoc_env_sign(char **input);

//handle_quote_mark.c
char	**append_cmd_options(char *arg);

//handle_quote_utils.c
void	skip_quote(char *arg, int *idx, char quote);
char	*realloc_option(char *option, int *idx, int *quotes_idx);
void	set_quotes_idx(char *option, int *idx, char quote, int *quotes_idx);
void	delete_quotes(char **option, int *flag);

//ms_init_cmd.c
void	set_isspace_to_blank(char *cmd);
void	set_list_struct_zero(t_cmd_list *list);
void	set_cmd_struct_zero(t_cmd *cmd);
int		init_struct(char *str, t_cmd_list *list);

//ms_make_list.c
void	make_list(t_cmd_list *list, char **cmd_split);

//ms_open_fd.c
void	set_eof(char *target, t_cmd *node);
void	set_single_input_fd(char *target, t_cmd *node);
void	set_single_output_fd(char *target, t_cmd *node);
void	set_double_output_fd(char *target, t_cmd *node);

//ms_parse_path.c
char	**get_path(char *path);
char	*parse_cmd_path(char *cmd, char **path);

//ms_seperate_cmd.c
char	**seperate_by_pipe(char *input);

#endif