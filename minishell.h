/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:12:29 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/10 21:13:11 by gitkim           ###   ########.fr       */
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




#endif