/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 14:50:21 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/07 19:00:27 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	handle_esc(t_params *params)
{
	t_params *tmp;

	tmp = params;
	REF_LOG;
	REF_SWP;
	printf("------\n");
	REF_LOG;
	exit(0);
}

void	handle_zoom(t_params *params, int dir)
{
	if (params->map->scale + ((float)dir * ZOOM_INC) > 0)
		params->map->scale += ((float)dir * ZOOM_INC);
	draw(params);
}



int		is_pan(int kc)
{
	return (kc == K_UP || kc == K_DOWN || kc == K_LEFT || kc == K_RIGHT);
}

int		is_zoom(int kc)
{
	return (kc == K_PLUS || kc == K_MINUS);
}
