/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:14:29 by ameta             #+#    #+#             */
/*   Updated: 2021/01/10 15:20:53 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

static void	ft_printx_min(t_params *params, unsigned int value, int *count)
{
	int				len;
	int				i;

	i = 0;
	len = ft_strlen(ft_itoa_hex(value));
	while (i < (params->precision - len))
	{
		ft_putchar('0');
		*count += 1;
		i++;
	}
	if (params->type == 'x')
		ft_putstr(ft_itoa_hex(value), 10000);
	else
		ft_putstr(ft_strtoupper(ft_itoa_hex(value)), 10000);
	*count += ft_strlen(ft_itoa_hex(value));
	while (i < (params->width - len))
	{
		ft_putchar(' ');
		*count += 1;
		i++;
	}
}

static void	ft_printx_zero(t_params *params, unsigned int value, int *count)
{
	int				len;
	int				i;

	i = 0;
	len = ft_strlen(ft_itoa_hex(value));
	params->precision = (params->precision < len) ? len :
							params->precision;
	while (i < (params->width - params->precision))
	{
		if (params->isprecision == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		*count += 1;
		i++;
	}
	i = len;
	while (i < (params->precision))
	{
		ft_putchar('0');
		*count += 1;
		i++;
	}
	if (params->type == 'x')
		ft_putstr(ft_itoa_hex(value), 1000);
	else
		ft_putstr(ft_strtoupper(ft_itoa_hex(value)), 1000);
	*count += ft_strlen(ft_itoa_hex(value));
}

static void	ft_printx_noflags(t_params *params, unsigned int value, int *count)
{
	int				len;
	int				i;

	i = 0;
	len = ft_strlen(ft_itoa_hex(value));
	params->precision = (params->precision < len) ? len :
							params->precision;
	while (i < (params->width - params->precision))
	{
		ft_putchar(' ');
		*count += 1;
		i++;
	}
	i = 0;
	while (i < (params->precision - len))
	{
		ft_putchar('0');
		*count += 1;
		i++;
	}
	if (params->type == 'x')
		ft_putstr(ft_itoa_hex(value), 1000);
	else
		ft_putstr(ft_strtoupper(ft_itoa_hex(value)), 1000);
	*count += ft_strlen(ft_itoa_hex(value));
}

void		ft_handle_x(t_params *params, va_list *ap, int *count)
{
	unsigned int	value;

	value = va_arg(*ap, unsigned int);
	if (value == 0 && params->width == 0 && params->isprecision == 0)
	{
		ft_putchar('0');
		*count += 1;
		return ;
	}
	if (params->isprecision == 1 && params->precision == 0 && value == 0)
	{
		ft_print_zero(params, count);
		return ;
	}
	if (params->flag_minus)
		ft_printx_min(params, value, count);
	else if (params->flag_zero)
		ft_printx_zero(params, value, count);
	else
		ft_printx_noflags(params, value, count);
}
