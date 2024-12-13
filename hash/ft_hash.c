/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:32:55 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/13 15:33:43 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_hash.h"
#include "libft.h"

size_t	get_hash_code(char *key, int key_len)
{
	unsigned char	*uc_key;
	size_t			idx;
	size_t			pow;
	size_t			hash_value;

	uc_key = (unsigned char *)key;
	idx = 0;
	pow = FT_HASH_POW;
	hash_value = 0;
	while (idx < key_len)
	{
		hash_value = (hash_value * pow + uc_key[idx]) % FT_HASH_TABLE;
		++idx;
	}
	return (hash_value);
}

t_hash	*make_hash(t_value_type value_type)
{
	t_hash	*hash;

	hash = ft_calloc(1, sizeof(t_hash));
	if (!hash)
		return (NULL);
	hash->value_type = value_type;
	return (hash);
}

void	free_hash_node(t_hash_node *node)
{
	free(node->key);
	free(node->s_value);
	free(node);
}

void	free_hash(t_hash *hash)
{
	int			idx;
	t_hash_node	*node;
	t_hash_node	*temp;

	idx = 0;
	while (idx < FT_HASH_TABLE)
	{
		node = hash->table[idx].head;
		while (node)
		{
			temp = node;
			node = node->next;
			free_hash_node(temp);
		}
		++idx;
	}
	free(hash);
}
