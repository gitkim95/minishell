/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_open_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:06:16 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/17 21:11:42 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "ms_parse.h"

void	set_eof(char *target, t_cmd *node)
{
	node->d_in_eof = target;
}

void	set_single_input_fd(char *target, t_cmd *node)
{
	node->s_in_fd = open(target, O_RDONLY);
	if (node->s_in_fd < 0)
		perror(target);
}

void	set_single_output_fd(char *target, t_cmd *node)
{
	node->s_out_fd = open(target, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (node->s_out_fd < 0)
		perror(target);
}

void	set_double_output_fd(char *target, t_cmd *node)
{
	node->d_out_fd = open(target, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (node->d_out_fd < 0)
		perror(target);
}
