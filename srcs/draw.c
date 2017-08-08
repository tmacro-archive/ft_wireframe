/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 12:57:55 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/07 19:10:04 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	render_line(t_display *display, t_line *line, int color)
{
	int d;
	int c;
	int	x;
	int	y;

	c = 0;
	d = 2 * line->dir->y - line->dir->x;
	x = line->start->x;
	y = line->start->y;
	while (c++ < line->dir->x)
	{
		if (x >= 0 && y >= 0)
			mlx_pixel_put(display->display, display->window, x, y, color);
		while (d >= 0)
		{
			d = d - 2 * line->dir->x;
			(line->swap) ? (x += line->sign->x) : (y += line->sign->y);
		}
		d = d + 2 * line->dir->y;
		(line->swap) ? (y += line->sign->y) : (x += line->sign->x);
	}
}

void	draw_line(t_display *display, t_tuple *s, t_tuple *e, int color)
{
	t_tuple *tmp;
	t_line	*line;
	int		swap;

	NULL_GUARD_NR((line = (t_line*)ft_memalloc(sizeof(t_line))));
	NULL_GUARD_NR((tmp = new_tuple(SIGN(e->x - s->x), SIGN(e->y - s->y))));
	line->sign = tmp;
	NULL_GUARD_NR((tmp = new_tuple(abs(e->x - s->x), abs(e->y - s->y))));
	line->dir = tmp;
	line->start = s;
	line->swap = 0;
	if (line->dir->y > line->dir->x)
	{
		swap = line->dir->y;
		line->dir->y = line->dir->x;
		line->dir->x = swap;
		line->swap = 1;
	}
	render_line(display, line, color);
}

void	render_segments(t_display *display, t_segment *segment, t_tuple *offset)
{
	NULL_GUARD_NR(segment);
//	printf("drawing line: %i, %i -> %i, %i color: %i\n", segment->start->x, segment->start->y, segment->end->x, segment->end->y, segment->color);
	draw_line(display, offset_point(segment->start, offset), offset_point(segment->end, offset), segment->color);
	render_segments(display, segment->next, offset);
}

void	draw_map(t_display *display, t_map *map)
{
		t_segment	*segments;
		t_tuple		*offset;

		offset = new_tuple(display->width / 2 + map->offset_x * 10, display->height / 2 + map->offset_y * 10);
		segments = build_segments(map);
		render_segments(display, segments, offset);
}
