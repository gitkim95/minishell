/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:22:09 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/14 14:25:52 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_BUILTIN_H
# define MS_BUILTIN_H

# include <ft_hash.h>

# define BUILTIN_HAS_OUTPUT	1
# define BUILTIN_NO_OUTPUT	2

typedef enum e_builtin
{
	MS_ECHO,
	MS_PWD,
	MS_ENV,
	MS_CD,
	MS_EXPORT,
	MS_UNSET,
	MS_EXIT
}	t_builtin;

/* ms_builtin */
t_hash	*get_builtin_hash(void);
int		is_builtin(char *cmd);
int		exec_builtin(char **argv);

int		ms_builtin_echo(char **argv);
int		ms_builtin_cd(char **argv);
int		ms_builtin_pwd(char **argv);
int		ms_builtin_export(char **argv);
int		ms_builtin_unset(char **argv);
int		ms_builtin_env(char **argv);

#endif