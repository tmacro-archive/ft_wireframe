/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 13:26:35 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/05 13:29:52 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clct.h"
#include <stdio.h>

int	region_log(t_region **region)
{
	printf(":: region %p\n  size: %lu\n  ref_count: %i\n", (*region)->address, (*region)->size, (*region)->ref_count);
	return (1);
}
