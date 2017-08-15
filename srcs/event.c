/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 12:50:39 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/15 10:08:41 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_pan(t_params *params, int x, int y)
{
	params->map->offset_x += x;
	params->map->offset_y += y;
	draw(params);
}

int		key_hook(int keycode, t_params *params)
{
	if (keycode == K_ESC)
		handle_esc(params);
	if (keycode == K_PLUS)
		handle_zoom(params, 1);
	if (keycode == K_MINUS)
		handle_zoom(params, -1);
	if (keycode == K_UP)
		handle_pan(params, 0, 1);
	if (keycode == K_DOWN)
		handle_pan(params, 0, -1);
	if (keycode == K_LEFT)
		handle_pan(params, 1, 0);
	if (keycode == K_RIGHT)
		handle_pan(params, -1, 0);
	REF_SWP;
	return (0);
}

int		expose_hook(t_params *params)
{
	draw(params);
	REF_SWP;
	return (0);
}

void	setup_hooks(t_params *params)
{
	mlx_do_key_autorepeaton(params->display->display);
	mlx_key_hook(params->display->window, &key_hook, params);
	mlx_expose_hook(params->display->window, &expose_hook, params);
}



