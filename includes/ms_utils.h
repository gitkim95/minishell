/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:39:55 by gitkim            #+#    #+#             */
/*   Updated: 2024/12/22 16:16:50 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_UTILS_H
# define MS_UTILS_H

# include "ms_struct.h"

# define MS_EXIT_SET 1
# define MS_EXIT_GET 0

//ms_utils_exit.c
int		ms_exit_status(int exit_status);
int		ms_exit(int flag);

//ms_utils.c
char	*ft_strcat(char *dest, const char *src);
int		ft_isspace(char c);
int		ft_strcmp(char *s1, char *s2);

//ms_mem_free.c
void	handle_hash_leak(void);
void	free_split(char **split);
void	clear_ms_list(t_cmd_list *list);
void	ms_terminator(t_cmd_list *list, int exit_flag, int exit_code);

#endif