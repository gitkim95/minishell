/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:32:55 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/12 17:17:23 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_hash.h"
#include "libft.h"

t_hash	*make_hash(t_value_type value_type)
{
	t_hash	*hash;

	hash = ft_calloc(1, sizeof(t_hash));
	if (!hash)
		return (NULL);
	hash->value_type = value_type;
	return (hash);
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
			free(temp->key);
			free(temp->s_value);
			free(temp);
		}
		++idx;
	}
	free(hash);
}
