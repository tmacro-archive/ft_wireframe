/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 00:39:11 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/07 14:44:32 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
t_tuple	*project_point(int x, int y, int z, int size)
{
	int		iso_x;
	int		iso_y;

	iso_x = (x - y) * (TILE_WIDTH * size) / 2;
	iso_y = (x + y) * (TILE_HEIGHT * size) / 2;
	iso_y -= z * 3;
	return (new_tuple(iso_x, iso_y));
}
*/


t_tuple	*adjust_center(t_map *map, t_tuple *p)
{
	int	x;
	int	y;

	x = p->x - (map->width / 2);
	y = p->y - (map->height / 2);
	return (new_tuple(x, y));
}

t_tuple *iso_project(t_map *map, t_tuple *p, int alt)
{
	double	iso_x;
	double	iso_y;
	double	width;
	double	height;

	width = (float)(TILE_WIDTH) * map->scale;
	height = (float)(TILE_HEIGHT) * map->scale;
	iso_x = TO_INT((float)(p->x - p->y) * width / 2.0);
	iso_y = TO_INT((float)(p->x + p->y) * height / 2.0);
	iso_y -= alt * 3;

	return (new_tuple(iso_x, iso_y));
}

t_tuple	*project_point(t_map *map, t_tuple *p)
{
	return (iso_project(map, adjust_center(map, p), map->map[0][p->y][p->x]));
}
