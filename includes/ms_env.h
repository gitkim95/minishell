/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:03:13 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/22 22:12:00 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_ENV_H
# define MS_ENV_H

# include "ft_hash.h"

# define MS_EXIT_CODE_KEY "?"
# define MS_IFS_KEY "IFS"

/* ms_env */
t_hash	*get_env_hash(void);
void	set_env_state(char *envp[]);

/* ms_env_utils */
char	*ms_get_env(char *key);
void	ms_set_env(char *key, char *value);
void	ms_del_env(char *key);

/* ms_env_array */
char	**get_env_array(void);

#endif