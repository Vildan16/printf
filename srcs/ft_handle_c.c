/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:13:38 by ameta             #+#    #+#             */
/*   Updated: 2021/01/10 15:18:16 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

static void	ft_printc_min(t_params *params, va_list *ap, int *count)
{
	int chr;
	int i;

	i = 0;
	chr = va_arg(*ap, int);
	ft_putchar((char)chr, count);
	while (i < (params->width - 1))
	{
		ft_putchar(' ', count);
		i++;
	}
}

static void	ft_printc_nomin(t_params *params, va_list *ap, int *count)
{
	int chr;
	int i;

	i = 0;
	chr = va_arg(*ap, int);
	while (i < (params->width - 1))
	{
		ft_putchar(' ', count);
		i++;
	}
	ft_putchar((char)chr, count);
}

void		ft_handle_c(t_params *params, va_list *ap, int *count)
{
	if (params->flag_minus == 1)
		ft_printc_min(params, ap, count);
	else
		ft_printc_nomin(params, ap, count);
}
