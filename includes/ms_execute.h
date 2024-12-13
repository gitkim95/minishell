/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:37:08 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/13 21:22:15 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_EXECUTE_H
# define MS_EXECUTE_H

# include <sys/types.h>
# include "ms_struct.h"

//ms_execute_logic.c
void	execute_logic(t_cmd_list *list);

//ms_close_fd.c
void	close_pipe_fd(t_cmd_list *list, int idx);
void	close_unnecessary_fd(t_cmd *node, t_cmd_list *list, int idx);

//ms_execute_cmd.c
void	execute_bulitin(t_cmd *node, t_cmd_list *list);
void	execute_cmd(t_cmd *node, t_cmd_list *list);

//ms_child_process.c
void	child_process(t_cmd_list *list, pid_t *pid);

//ms_init_var.c
void	alloc_pipe_fd(t_cmd_list *list);
void	init_pipe_fd(t_cmd_list *list);
pid_t	*init_pid_arr(t_cmd_list *list);

//ms_script_loop.c
void	script_loop(t_cmd_list *list);

//ms_set_pipe.c
void	set_input_descriptor(t_cmd *node, t_cmd_list *list, int idx);
void	set_output_descriptor(t_cmd *node, t_cmd_list *list, int idx);
void	pipe_connect_process(t_cmd *node, t_cmd_list *list, int idx);

#endif