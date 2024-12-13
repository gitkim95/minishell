/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:39:55 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/13 16:12:21 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_UTILS_H
# define MS_UTILS_H

# include "ms_struct.h"

//ms_utils.c
char	*ft_strcat(char *dest, const char *src);
int		ft_isspace(char c);

//ms_mem_free.c
void	free_split(char **split);
void	clear_ms_list(t_cmd_list *list);
void	free_struct(t_cmd_list *list);

#endif