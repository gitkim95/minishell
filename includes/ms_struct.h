/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:28:08 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/12 18:05:02 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_STRUCT_H
# define MS_STRUCT_H

# include <errno.h>
# define MS_BUFFER_SIZE 1024

typedef struct s_cmd
{
	char			**av;
	int				s_in_fd;
	int				s_out_fd;
	char			*d_in_eof;
	int				d_out_fd;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_cmd_list
{
	t_cmd	*head;
	t_cmd	*tail;
	int		size;
	int		**pipe_fd;
}	t_cmd_list;

#endif