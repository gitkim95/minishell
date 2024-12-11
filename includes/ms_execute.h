/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:37:08 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/11 21:46:18 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_EXECUTE_H
# define MS_EXECUTE_H

# include "ms_struct.h"

//ms_execute_cmd.c
void	execute_cmd(t_cmd_list *list);

//ms_script_roop.c
void	script_roop(t_cmd_list *list);

#endif