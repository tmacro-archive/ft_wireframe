/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clct_ref.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 11:02:05 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/07 16:00:43 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clct.h"
#include "libft.h"
#include <stdio.h>

int	ref_inc(t_region **region)
{
	return (++((*region)->ref_count));
}

int	ref_dec(t_region **region)
{
	if ((*region)->ref_count > 0)
		return (--((*region)->ref_count));
	return (0);
}

int	ref_sweep(t_region **region)
{
	void *tmp;

	printf("sweep: %p, %p\n", region, *region);
	if ((*region)->ref_count <= 0)
	{
		tmp = (*region)->next;
		free((*region)->address);
		free(*region);
		*region = tmp;
		return (1);
	}
	return (0);
}

int	ref_clean(t_region **region)
{
	t_region *tmp;
	t_region *f;
	
	tmp = (*region)->next;
	printf("clean: %p, %p\n", (*region)->next, (*region)->address);
	f = (*region)->address;
	free(f);
	printf("clean: %p\n", f);
	free(*region);
	*region = tmp;
	return (1);
}

