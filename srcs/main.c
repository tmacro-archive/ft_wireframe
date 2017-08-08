/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 12:40:19 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/07 11:56:22 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_params	*params;

	if (ac > 1)
	{
		ERR_CNR((params = (t_params*)ft_memalloc(sizeof(t_params))), NULL, 1);
		params->display = create_window(1000, 1000);
		params->map = load_map(*(av + 1));
		setup_hooks(params);
		draw(params);
		mlx_loop(params->display->display);
	}
	else
		ft_putstr("Usage: ./fdf <map>\n");
	return (0);
}

void	draw(t_params *params)
{
	mlx_clear_window(params->display->display, params->display->window);
	draw_map(params->display, params->map);
}
