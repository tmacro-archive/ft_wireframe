/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 12:40:19 by tmckinno          #+#    #+#             */
/*   Updated: 2017/07/31 14:50:29 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	t_display	*display;
	int			fd;
	t_map		*map;
	t_segment	*segments;

	display = create_window(1000, 1000);
	if (ac > 1)
	{
		fd = open(*(av + 1), O_RDONLY);
		map = load_map(fd);
		segments = build_segments(map, 1);
		render_segments(display, segments);
	}
	mlx_loop(display->display);
	return (0);
}
