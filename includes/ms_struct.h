/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:28:08 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/23 18:54:40 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_STRUCT_H
# define MS_STRUCT_H

# include <errno.h>
# define MS_BUFFER_SIZE 4096
# define PID_INIT -2

typedef struct s_cmd
{
	char			**av;
	int				s_in_fd;
	int				s_out_fd;
	int				hd_pipe_fd[2];
	int				heredoc_quote_flag;
	char			*d_in_eof;
	int				d_out_fd;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

typedef struct s_cmd_list
{
	t_cmd	*head;
	t_cmd	*tail;
	int		size;
	int		**pipe_fd;
}	t_cmd_list;

#endif