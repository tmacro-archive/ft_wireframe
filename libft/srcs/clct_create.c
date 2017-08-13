/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 13:37:12 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/10 15:11:58 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdict.h"

static t_dict	internal_dict_create(size_t size, t_hasher hasher)
{
	t_dict	dict;
	size_t	i;

	dict = (t_dict)malloc(sizeof(*dict));
	dict->size = size;
	dict->stored = 0;
	dict->hasher = hasher;
	dict->buckets = malloc(sizeof(t_fdict_el) * dict->size);
	i = 0;
	while (i < dict->size)
		dict->buckets[i++] = 0;
	return (dict);
}

t_dict			dict_create(unsigned long (*hasher)())
{
	return (internal_dict_create(FDICT_INITIAL_SIZE, hasher));
}

void			dict_grow(t_dict dict)
{
	t_dict			new_dict;
	struct s_fdict	swap;
	t_fdict_el		*e;
	size_t			i;

	new_dict = internal_dict_create(dict->size * FDICT_GROWTH_FACTOR,
									dict->hasher);
	i = 0;
	while (i < dict->size)
	{
		e = dict->buckets[i];
		while (e)
		{
			dict_set(new_dict, e->key, e->value);
			e = e->next;
		}
		i++;
	}
	swap = *dict;
	*dict = *new_dict;
	*new_dict = swap;
	dict_destroy(new_dict);
}

void			dict_destroy(t_dict dict)
{
	size_t		i;
	t_fdict_el	*e;
	t_fdict_el	*next;

	i = 0;
	while (i < dict->size)
	{
		e = dict->buckets[i];
		while (e)
		{
			next = e->next;
			free(e);
			e = next;
		}
		i++;
	}
	free(dict->buckets);
	free(dict);
}
