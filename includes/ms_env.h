/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:03:13 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/15 18:56:57 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_ENV_H
# define MS_ENV_H

# include "ft_hash.h"

/* ms_env */
t_hash	*get_env_hash(void);
char	**get_env_str_arr(void);
void	set_env_state(char *envp[]);

/* ms_env_utils */
char	*ms_get_env(char *key);
void	ms_set_env(char *key, char *value);
void	ms_del_env(char *key);

#endif