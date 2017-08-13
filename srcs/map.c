/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 21:11:45 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/13 14:35:19 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

int		map_width(char *line)
{
	int		width;
	char	**split;

	split = ft_strsplit(line, ' ');
	width = 0;
	while (*split)
	{
		width++;
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
	while (*line)
	{
		if (!(ft_isdigit(*line) || *line == ' '))
			return (NULL);
		line++;
	}
	len = arr_len(split);
	ERR_CNRF((row = (int*)ft_memalloc(len * sizeof(int))), NULL, NULL, split);
	pos = row;
	while (*split)
	{
		*pos++ = ft_atoi(*split);
		split++;
	}
	return (row);
}

int		extend_map(int ***map, int *row, int len)
{
	int	**new;
	int	pos;

	if (!row)
		return (0);
	new = (int**)ft_memalloc(sizeof(int*) * (len + 1));
	REF_INC(new);
	pos = 0;
	while (pos < len)
	{
		new[pos] = map[0][pos];
		pos++;
	}
	new[pos] = row;
	REF_INC(row);
	REF_DEC(*map);
	*map = new;
	return (1);
}

t_map	*load_map(char *file)
{
	char	*line;
	t_map	*map;
	int		fd;

	NULL_GUARD((map = (t_map*)ft_memalloc(sizeof(t_map))));
	map->map = (int***)ft_memalloc(sizeof(int**));
	REF_INC(map->map);
	map->height = 0;
	map->width = -1;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (map->width != -1 && map->width != map_width(line))
			return (NULL);
		(map->width == -1) ? (map->width = map_width(line)) : (1);
		if (!extend_map(map->map, parse_row(line), map->height++))
			return (NULL);
	}
	close(fd);
	map->offset_x = 0;
	map->offset_y = 0;
	map->tile_width = TILE_WIDTH;
	map->tile_height = TILE_HEIGHT;
	map->scale = 1;
	return (map);
}
