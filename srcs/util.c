/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 15:20:57 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/07 14:49:08 by tmckinno         ###   ########.fr       */
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

t_tuple		*offset_point(t_tuple *p, t_tuple *offset)
{
	return (new_tuple(p->x + offset->x, p->y + offset->y));
}
