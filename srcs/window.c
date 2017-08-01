/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:16:11 by tmckinno          #+#    #+#             */
/*   Updated: 2017/07/31 14:48:39 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*create_window(int w, int h)
{
	t_display	*ds;

	NULL_GUARD((ds = (t_display*)ft_memalloc(sizeof(t_display))));
	NULL_GUARD((ds->display = mlx_init()));
	NULL_GUARD((ds->window = mlx_new_window(ds->display, w, h, "FDF")));
	ds->width = w;
	ds->height = h;
	return (ds);
}
