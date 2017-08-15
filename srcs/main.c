/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 12:40:19 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/15 10:31:36 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		cleanup()
{
	REF_CLN;
	return (0);
}

int		main(int ac, char **av)
{
	t_params	*params;

	if (ac > 1)
	{
		ERR_CNR((params = (t_params*)ft_memalloc(sizeof(t_params))), NULL, 1);
		REF_INC(params);
		params->map = load_map(*(av + 1));
		if (!params->map)
			return(cleanup());
		else
		if (params->map->height == 0)
		{
			empty_or_invalid_error();
			return (cleanup());
		}
		params->display = create_window(1000, 1000);
		setup_hooks(params);
		draw(params);
		REF_INC(params->map);
		REF_INC(params->display);
		mlx_loop(params->display->display);
	}
	else
		ft_putstr("Usage: ./fdf <map>\n");
	return (cleanup());
}

void	draw(t_params *params)
{
	mlx_clear_window(params->display->display, params->display->window);
	draw_map(params->display, params->map);
}
