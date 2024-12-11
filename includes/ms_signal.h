/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:46:59 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/11 21:48:58 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_SIGNAL_H
# define SIGNAL_H

void	register_signal_hander();
void	reset_signal_hander();
void	sigint_handler(int sig);
void	sigquit_handler(int sig);

#endif