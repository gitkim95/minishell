/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:12:29 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/11 15:39:21 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MS_BUFFER_SIZE 1024

typedef struct	s_cmd
{
	char			**av;
	char			*s_input;
	char			*s_output;
	char			*d_input;
	char			*d_output;
	struct s_cmd	*next;
}	t_cmd;

typedef struct	s_cmd_list
{
	t_cmd	*head;
	t_cmd	*tail;
	int		size;
}	t_cmd_list;

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection_sign.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:30:07 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/11 15:22:21 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./libft/libft.h"

//check_redirection_sign.c
char	*get_redirection_target(char *cmd_str);
int		is_double_input(char *cmd_str, t_cmd *node);
int		is_single_input(char *cmd_str, t_cmd *node);
int		is_double_output(char *cmd_str, t_cmd *node);
int		is_single_output(char *cmd_str, t_cmd *node);

//ms_utils.c
char	*ft_strcat(char *dest, const char *src);

#endif