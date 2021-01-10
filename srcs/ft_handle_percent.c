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
	while (i < (params->precision - 1))
	{
		ft_putchar('0');
		*count += 1;
		i++;
	}
	ft_putchar('%');
	*count += 1;
	while (i < (params->width - 1))
	{
		ft_putchar(' ');
		*count += 1;
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
		if (params->precision == -1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		*count += 1;
		i++;
	}
	i = 1;
	while (i < (params->precision))
	{
		ft_putchar('0');
		i++;
		*count += 1;
	}
	ft_putchar('%');
	*count += 1;
}

static void	ft_printperc_noflags(t_params *params, int *count)
{
	int i;

	i = 0;
	while (i < (params->width - 1))
	{
		ft_putchar(' ');
		*count += 1;
		i++;
	}
	while (i < (params->precision - 1))
	{
		ft_putchar('0');
		i++;
		*count += 1;
	}
	ft_putchar('%');
	*count += 1;
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
