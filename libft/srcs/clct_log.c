/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clct_log.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 13:26:35 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/13 14:20:36 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clct.h"
#include "libft.h"

int	logger(void *key, void *value)
{
	t_region	*region;
	void		*trash;

	trash = key;
	region = (t_region*)value;
	return (1);
}

int	region_log(t_dict regions)
{
	t_dict	tmp;

	tmp = regions;
	return (1);
}
