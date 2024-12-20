/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:46:59 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/20 18:46:05 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_SIGNAL_H
# define MS_SIGNAL_H

# include "ms_struct.h"

void	register_signal_handler(void);
void	register_heredoc_signal_handler(t_cmd *cmd);
void	block_signal(void);
void	unblock_signal(void);

#endif