/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 10:00:12 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/15 10:23:35 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*map_width_error(int exp, int obs, int line)
{
	ft_putstr("Error: Line ");
	ft_putnbr(line);
	ft_putstr(" is ");
	ft_putnbr(obs);
	ft_putstr(" expected ");
	ft_putnbr(exp);
	ft_putstr("\n");
	return (NULL);
}

void	*invalid_row_error()
{
	ft_putstr("Error: Invalid row\n");
	return (NULL);
}

void	*empty_or_invalid_error()
{
	ft_putstr("Error: Empty or Nonexistent Map\n");
	return (NULL);
}
