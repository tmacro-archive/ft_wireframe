/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clct_region.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 15:14:19 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/13 13:23:29 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clct.h"

int	region_manip(void *addr, int mode, size_t len)
{
	static t_dict regions;

	if (!regions)
		regions = VDICT;
	if (mode == RM_ALLC)
		return (region_add(regions, addr, len));
	if (mode == RM_FREE)
		return (region_rem(regions, addr));
	if (mode == RM_RINC)
		return (ref_inc(regions, addr));
	if (mode == RM_RDEC)
		return (ref_dec(regions, addr));
	if (mode == RM_RSWP)
		return (ref_sweep(regions));
	if (mode == RM_RCLN)
	{
		ref_clean(regions);
		dict_destroy(regions);
		regions = NULL;
	}
	if (mode == RM_RLOG)
		return (region_log(regions));
	return (-1);
}

int	region_add(t_dict regions, void *addr, size_t len)
{
	t_region *new;

	new = (t_region*)malloc(sizeof(t_region));
	if (new == NULL)
		return (0);
	new->address = addr;
	new->size = len;
	new->ref_count = 0;
	DSET(regions, addr, new);
	return (1);
}

int	region_rem(t_dict regions, void *addr)
{
	t_region	*tmp;

	tmp = DGET(regions, addr);
	if (tmp)
	{
		DREM(regions, addr);
		free(tmp);
	}
	return (0);
}
