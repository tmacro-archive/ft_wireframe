/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 21:11:45 by tmckinno          #+#    #+#             */
/*   Updated: 2017/07/31 18:20:18 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include <stdio.h>

int		map_width(char *line)
{
	int		width;
	char	**split;

	split = ft_strsplit(line, ' ');
	width = 0;
	while (*split)
	{
		width++;
		free(*split);
		split++;
	}
	return (width);
}

int		*parse_row(char *line)
{
	int		*row;
	int		*pos;
	int		len;
	char	**split;

	split = ft_strsplit(line, ' ');
	len = arr_len(split);
	ERR_CNRF((row = (int*)ft_memalloc(len * sizeof(int))), NULL, NULL, split);
	pos = row;
	while (*split)
	{
		*pos++ = ft_atoi(*split);
		free(*split);
		split++;
	}
//	free(split);
	return (row);
}

void	extend_map(int ***map, int *row, int len)
{
	int	**new;
	int	pos;

	new = (int**)ft_memalloc(sizeof(int*) * (len + 1));
	pos = 0;
	while (pos < len)
	{
		new[pos] = map[0][pos];
		pos++;
	}
	new[pos] = row;
	free(*map);
	*map = new;
}

t_map	*load_map(int fd)
{
	char	*line;
	t_map	*map;

	NULL_GUARD((map = (t_map*)ft_memalloc(sizeof(t_map))));
	map->map = (int***)ft_memalloc(sizeof(int**));
	map->height = 0;
	map->width = -1;
	while (get_next_line(fd, &line) > 0)
	{
		if (map->width == -1)
			map->width = map_width(line);
		extend_map(map->map, parse_row(line), map->height++);
		free(line);
	}
	map->offset_x = map->width / 2 - 1;
	map->offset_y = map->height / 2 - 1;
	map->tile_width = TILE_WIDTH;
	map->tile_height = TILE_HEIGHT;
	return (map);
}
