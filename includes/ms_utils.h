/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:39:55 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/15 02:25:40 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_UTILS_H
# define MS_UTILS_H

# include "ms_struct.h"

//ms_utils.c
char	*ft_strcat(char *dest, const char *src);
int		ft_isspace(char c);
int		ft_strcmp(char *s1, char *s2);

//ms_mem_free.c
void	handle_hash_leak(void);
void	free_split(char **split);
void	clear_ms_list(t_cmd_list *list);
void	ms_terminator(t_cmd_list *list, int exit_code, int exit_flag);

#endif