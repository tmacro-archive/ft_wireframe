/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 00:39:11 by tmckinno          #+#    #+#             */
/*   Updated: 2017/07/31 15:26:58 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_tuple	*project_point(int x, int y, int z, int size)
{
	int		iso_x;
	int		iso_y;

	iso_x = (x - y) * (TILE_WIDTH * size) / 2;
	iso_y = (x + y) * (TILE_HEIGHT * size) / 2;
	iso_y -= z * 3;
	return (new_tuple(iso_x, iso_y));
}
