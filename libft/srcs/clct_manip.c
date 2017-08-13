/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clct_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 14:07:21 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/13 13:27:17 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdict.h"

void	*dict_get(t_dict dict, void *key)
{
	t_fdict_el	*e;

	e = dict->buckets[dict->hasher(key) % dict->size];
	while (e)
	{
		if (e->key == key)
			return (e->value);
		e = e->next;
	}
	return (NULL);
}

void	dict_set(t_dict dict, void *key, void *value)
{
	t_fdict_el	*e;
	t_ulong		hash;

	e = malloc(sizeof(t_fdict_el));
	e->key = key;
	e->value = value;
	hash = dict->hasher(key) % dict->size;
	e->next = dict->buckets[hash];
	dict->buckets[hash] = e;
	dict->stored++;
	if (dict->stored >= dict->size * FDICT_MAX_LOAD)
		dict_grow(dict);
}

void	dict_rem(t_dict dict, void *key)
{
	t_fdict_el	**prev;
	t_fdict_el	*e;

	prev = &(dict->buckets[dict->hasher(key) % dict->size]);
	while (*prev != NULL)
	{
		if ((*prev)->key == key)
		{
			e = *prev;
			*prev = e->next;
			free(e);
			dict->stored--;
			break ;
		}
		prev = &((*prev)->next);
	}
}

void	dict_iter(t_dict dict, int (*f)(void *key, void *value))
{
	size_t		i;
	t_fdict_el	*e;

	i = 0;
	while (i < dict->size)
	{
		e = dict->buckets[i];
		while (e)
		{
			f(e->key, e->value);
			e = e->next;
		}
		i++;
	}
}
