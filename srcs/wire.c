/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wire.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 10:10:49 by tmckinno          #+#    #+#             */
/*   Updated: 2017/07/31 15:42:14 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_segment	*build_segment_r(t_map *map, int x, int y, int scale)
{
	t_tuple	*start;
	t_tuple	*end;
	int		color;

	start = project_point(x, y, map->map[0][y][x], scale);
	end = project_point(x + 1, y, map->map[0][y][x + 1], scale);
	color = gen_color((map->map[0][y][x] + map->map[0][y][x + 1]) / 2);
	return (new_segment(start, end, color));
}

t_segment	*build_segment_d(t_map *map, int x, int y, int scale)
{
	t_tuple	*start;
	t_tuple	*end;
	int		color;

	start = project_point(x, y, map->map[0][y][x], scale);
	end = project_point(x, y + 1, map->map[0][y + 1][x], scale);
	color = gen_color((map->map[0][y][x] + map->map[0][y + 1][x]) / 2);
	return (new_segment(start, end, color));
}

t_segment	*build_segments(t_map *map, int scale)
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
				push_segment(segments, build_segment_r(map, x, y, scale));
			if (y < map->height - 1)
				push_segment(segments, build_segment_d(map, x, y, scale));
			y++;
		}
		x++;
	}
	return (*segments);
}
