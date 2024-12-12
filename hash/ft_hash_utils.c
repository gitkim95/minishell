/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:53:29 by hwilkim           #+#    #+#             */
/*   Updated: 2024/12/12 18:04:23 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_hash.h"
#include "libft.h"

static int			ft_strcmp(char *s1, char *s2);
static size_t		get_hash_code(char *key, int key_len);
static t_hash_node	*get_new_node(t_hash *hash, char *key, void *value);

t_hash_node	*get_hash_node(t_hash *hash, char *key)
{
	size_t		hash_code;
	t_hash_node	*node;

	hash_code = get_hash_code(key, ft_strlen(key));
	node = (hash->table)[hash_code].head;
	while (node)
	{
		if (ft_strcmp(key, node->key) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	*put_hash_value(t_hash *hash, char *key, void *value)
{
	t_hash_table	*table;
	t_hash_node		*node;

	node = get_hash_node(hash, key);
	if (node)
		return (node);
	node = get_new_node(hash, key, value);
	table = &(hash->table[get_hash_code(key, ft_strlen(key))]);
	if (!(table->head))
	{
		table->head = node;
		table->tail = node;
	}
	else
	{
		table->tail->next = node;
		table->tail = node;
	}
	++(hash->size);
	return (node);
}

static size_t	get_hash_code(char *key, int key_len)
{
	unsigned char	*uc_key;
	size_t			idx;
	size_t			pow;
	size_t			hash_value;

	uc_key = (unsigned char *)key;
	idx = 0;
	pow = FT_HASH_TABLE;
	hash_value = 0;
	while (idx < key_len)
	{
		hash_value = (hash_value + uc_key[idx] * pow) % FT_HASH_TABLE;
		++idx;
	}
	return (hash_value);
}

static t_hash_node	*get_new_node(t_hash *hash, char *key, void *value)
{
	t_hash_node	*node;

	node = ft_calloc(1, sizeof(t_hash_node));
	if (!node)
		return (NULL);
	node->key = ft_strdup(key);
	if (hash->value_type == FT_HASH_INT)
		node->i_value = *((int *)value);
	else
		node->s_value = ft_strdup((const char *)value);
	return (node);
}

static int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	c1;
	unsigned char	c2;
	unsigned int	idx;

	idx = 0;
	while (s1[idx] != '\0' && s2[idx] != '\0')
	{
		c1 = s1[idx];
		c2 = s2[idx];
		if (c1 != c2)
			return (c1 - c2);
		++idx;
	}
	c1 = s1[idx];
	c2 = s2[idx];
	return (c1 - c2);
}
