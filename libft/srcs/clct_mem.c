/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clct_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 15:50:41 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/07 15:12:50 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clct.h"

void	*memalloc(size_t len)
{
	void			*freshmeat;

	freshmeat = (void*)malloc(len);
	if (freshmeat == NULL)
		return (NULL);
	region_manip(freshmeat, 1, len);
	return (freshmeat);
}

int		memfree(void **addr)
{
	if (addr && region_manip(*addr, 2, 0) == 1)
	{
		free(*addr);
		*addr = NULL;
		return (1);
	}
	return (0);
}
