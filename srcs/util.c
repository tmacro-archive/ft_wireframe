/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 15:20:57 by tmckinno          #+#    #+#             */
/*   Updated: 2017/07/31 14:56:33 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <unistd.h>

t_tuple		*new_tuple(int x, int y)
{
	t_tuple *freshmeat;

	NULL_GUARD((freshmeat = (t_tuple*)ft_memalloc(sizeof(t_tuple))));
	freshmeat->x = x;
	freshmeat->y = y;
	return (freshmeat);
}

int			*build_point(int x, int y, int z, int scale)
{
	int	*tmp;

	tmp = (int*)ft_memalloc(sizeof(int) * 4);
	tmp[0] = x;
	tmp[1] = y;
	tmp[2] = z;
	tmp[3] = scale;
	return (tmp);
}

int			arr_len(char **arr)
{
	int len;

	len = 0;
	while (*arr++)
		len++;
	return (len);
}

void		push_segment(t_segment **segs, t_segment *new)
{
	new->next = *segs;
	*segs = new;
}

t_segment	*new_segment(t_tuple *start, t_tuple *end, int color)
{
	t_segment	*new;

	NULL_GUARD((new = ft_memalloc(sizeof(t_segment))));
	new->start = start;
	new->end = end;
	new->color = color;
	return (new);
}
