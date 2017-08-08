/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clct_region.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 15:14:19 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/07 19:01:09 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clct.h"
#include <stdio.h>

int		region_manip(void *addr, int mode, size_t len)
{
	static t_region **regions;

	if (!regions)
	{
		regions = (t_region**)malloc(sizeof(t_region*));
		*regions = NULL;
	}
	if (mode == 1)
		return (region_add(regions, addr, len));
	if (mode == 2)
		region_iter(regions, addr, &region_rem);
	if (mode == 3)
		region_iter(regions, addr, &ref_inc);
	if (mode == 4)
		region_iter(regions, addr, &ref_dec);
	if (mode == 5)
		region_iter(regions, NULL, &region_log);
	if (mode == 6)
		region_iter(regions, NULL, &ref_sweep);
	if (mode == RM_RCLN)
		region_iter(regions, NULL, &ref_clean);
	return (1);
}

int		region_add(t_region **regions, void *addr, size_t len)
{
	t_region *new;

	new = (t_region*)malloc(sizeof(t_region));
	if (new == NULL)
		return (0);
	new->address = addr;
	new->size = len;
	new->ref_count = 0;
	new->next = *regions;
	*regions = new;
	return (1);
}

int		region_rem(t_region **region)
{
	void *tmp;

	if (region && *region)
	{
		tmp = (*region)->next;
		free(*region);
		*region = tmp;
		return (1);
	}
	return (0);
}
/*
void	region_iter(t_region **regions, void *addr, int (*f)(t_region **r))
{	
	t_region	*tmp;

	if (regions && *regions)
	{
		if ((*regions)->address == addr)
			f(regions);
		else
		{
			tmp = (*regions)->next;
			if (addr == NULL)
				f(regions);
			if (tmp != *regions)
				region_iter(&(*regions)->next, addr, f);
			else
				region_iter(regions, addr, f);
		}
	}
}
*/
void	region_iter(t_region **regions, void *addr, int (*f)(t_region **r))
{
	t_region	**current;
	t_region	*next;

	current = regions;
	while (*current)
	{
		next = (*current)->next;
//		printf("-----\niter 1 %p == %p -> %p\n", current, addr, next);
		if ((*current)->address == addr && addr != NULL)
		{
			f(current);
			break ;
		}
		if (addr == NULL)
			f(current);
		if (next != *current)
			*current = (*current)->next;
		else
			*current = next;
//		printf("iter 2 %p == %p -> %p\n-----\n", current, addr, next);
	}
}
