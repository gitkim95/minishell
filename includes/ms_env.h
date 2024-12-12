/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:03:13 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/12 21:21:13 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_ENV_H
# define MS_ENV_H

# include "ft_hash.h"

t_hash	*get_env_hash(void);
char	*get_env_value(char *key);
void	set_env_state(char *envp[]);

#endif