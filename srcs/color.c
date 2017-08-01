/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 13:00:41 by tmckinno          #+#    #+#             */
/*   Updated: 2017/07/31 15:00:40 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	pack_color(int r, int g, int b)
{
	int color;

	color = 0;
	color |= (0 & 255) << 24;
	color |= (r & 255) << 16;
	color |= (g & 255) << 8;
	color |= (b & 255);
	return (color);
}

int	gen_color(int z)
{
	int r;
	int g;
	int b;

	r = sin(1.666 * z + 0) * 200 * 55;
	g = sin(2.666 * z + 2) * 200 * 55;
	b = sin(4.666 * z + 4) * 200 * 55;
	return (pack_color(r, g, b));
}
