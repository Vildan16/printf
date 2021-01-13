/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:14:06 by ameta             #+#    #+#             */
/*   Updated: 2021/01/10 15:20:05 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

static void	ft_printperc_min(t_params *params, int *count)
{
	int i;

	i = 0;
	ft_putchar('%', count);
	while (i < (params->width - 1))
	{
		ft_putchar(' ', count);
		i++;
	}
}

static void	ft_printperc_zero(t_params *params, int *count)
{
	int i;

	i = 0;
	params->precision = (params->precision == 0) ? 1 :
							params->precision;
	while (i < (params->width - params->precision))
	{
		if (params->isprecision == 0)
			ft_putchar('0', count);
		else
			ft_putchar(' ', count);
		i++;
	}
	i = 1;
	ft_putchar('%', count);
}

static void	ft_printperc_noflags(t_params *params, int *count)
{
	int i;

	i = 0;
	while (i < (params->width - 1))
	{
		ft_putchar(' ', count);
		i++;
	}
	ft_putchar('%', count);
}

void		ft_handle_percent(t_params *params, int *count)
{
	if (params->flag_minus)
		ft_printperc_min(params, count);
	else if (params->flag_zero)
		ft_printperc_zero(params, count);
	else
		ft_printperc_noflags(params, count);
}
