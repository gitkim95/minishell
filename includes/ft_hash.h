/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:31:01 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/13 17:05:39 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASH_H
# define FT_HASH_H

# define FT_HASH_POW 31
# define FT_HASH_TABLE 53

# include <stddef.h>

typedef enum e_value_type
{
	FT_HASH_INT,
	FT_HASH_STR
}	t_value_type;

typedef struct s_hash_node
{
	char				*key;
	char				*s_value;
	int					i_value;
	struct s_hash_node	*next;
}	t_hash_node;

typedef struct s_hash_table
{
	t_hash_node	*head;
	t_hash_node	*tail;
}	t_hash_table;

typedef struct s_hash
{
	t_hash_table	table[FT_HASH_TABLE];
	t_value_type	value_type;
	int				size;
}	t_hash;

/* utils */
t_hash_node	*get_hash_node(t_hash *hash, char *key);
void		*put_hash_value(t_hash *hash, char *key, void *value);
void		*put_hash_value_int(t_hash *hash, char *key, int value);
void		remove_hash_value(t_hash *hash, char *key);

size_t		get_hash_code(char *key, size_t key_len);
t_hash		*make_hash(t_value_type value_type);
void		free_hash_node(t_hash_node *node);
void		free_hash(t_hash *hash);

#endif