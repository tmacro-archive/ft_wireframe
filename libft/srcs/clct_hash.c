/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clct_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 14:52:49 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/13 13:26:45 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdict.h"

t_ulong	hash_ptr(void *value)
{
	t_ulong	hash;

	hash = (t_ulong)value;
	return (hash);
}

t_ulong	hash_str(void *value)
{
	t_ulong	hash;
	char	*pos;

	hash = 0;
	pos = (char*)value;
	while (*pos)
	{
		hash *= 97 * (unsigned char)(*pos);
		pos++;
	}
	return (hash);
}

t_ulong	hash_int(void *value)
{
	int		key;
	t_ulong	hash;

	key = *(int*)value;
	hash = (t_ulong)key;
	return (hash);
}
