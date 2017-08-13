/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wire.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 10:10:49 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/13 13:09:44 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_segment	*new_segment(t_tuple *start, t_tuple *end, int color)
{
	t_segment	*new;

	NULL_GUARD((new = ft_memalloc(sizeof(t_segment))));
	new->start = start;
	new->end = end;
	new->color = color;
	return (new);
}

t_segment	*build_segment_r(t_map *map, int x, int y)
{
	t_tuple	*start;
	t_tuple	*end;
	int		color;

	start = project_point(map, new_tuple(x, y));
	end = project_point(map, new_tuple(x + 1, y));
	color = gen_color((map->map[0][y][x] + map->map[0][y][x + 1]) / 2);
	return (new_segment(start, end, color));
}

t_segment	*build_segment_d(t_map *map, int x, int y)
{
	t_tuple	*start;
	t_tuple	*end;
	int		color;

	start = project_point(map, new_tuple(x, y));
	end = project_point(map, new_tuple(x, y + 1));
	color = gen_color((map->map[0][y][x] + map->map[0][y + 1][x]) / 2);
	return (new_segment(start, end, color));
}

void		push_segment(t_segment **segs, t_segment *new)
{
	new->next = *segs;
	*segs = new;
}

t_segment	*build_segments(t_map *map)
{
	int			x;
	int			y;
	t_segment	**segments;

	segments = (t_segment**)ft_memalloc(sizeof(t_segment*));
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			if (x < map->width - 1)
				push_segment(segments, build_segment_r(map, x, y));
			if (y < map->height - 1)
				push_segment(segments, build_segment_d(map, x, y));
			y++;
		}
		x++;
	}
	return (*segments);
}
