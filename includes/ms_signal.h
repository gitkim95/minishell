/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:46:59 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/22 21:31:39 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_SIGNAL_H
# define MS_SIGNAL_H

# define MS_STORE_TERMINAL_STATE	1
# define MS_RESTORE_TERMINAL_STATE	0

/* ms_signal_heredoc */
void	register_heredoc_signal_handler(t_cmd_list *list);
void	terminal_state(int store_flag);

/* ms_signal */
void	register_signal_handler(void);
void	block_signal(void);
void	unblock_signal(void);

#endif