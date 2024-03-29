/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:14:29 by ameta             #+#    #+#             */
/*   Updated: 2021/01/16 17:09:13 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

static void	ft_printx_min(t_params *params, unsigned int value, int *count)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa_hex(value);
	len = ft_strlen(str);
	while (i < (params->precision - len))
	{
		ft_putchar('0', count);
		i++;
	}
	if (params->type == 'x')
		ft_putstr(str, 10000, count);
	else
		ft_putstr(ft_strtoupper(str), 10000, count);
	while (i < (params->width - len))
	{
		ft_putchar(' ', count);
		i++;
	}
	free(str);
}

static void	ft_printx_zero(t_params *params, unsigned int value, int *count)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa_hex(value);
	len = ft_strlen(str);
	params->precision = (params->precision < len) ? len :
							params->precision;
	while (i < (params->width - params->precision))
	{
		(params->isprecision == 0) ? ft_putchar('0', count)
			: ft_putchar(' ', count);
		i++;
	}
	i = len;
	while (i < (params->precision))
	{
		ft_putchar('0', count);
		i++;
	}
	(params->type == 'x') ? ft_putstr(str, 1000, count) :
		ft_putstr(ft_strtoupper(str), 1000, count);
	free(str);
}

static void	ft_printx_noflags(t_params *params, unsigned int value, int *count)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa_hex(value);
	len = ft_strlen(str);
	params->precision = (params->precision < len) ? len :
							params->precision;
	while (i < (params->width - params->precision))
	{
		ft_putchar(' ', count);
		i++;
	}
	i = 0;
	while (i < (params->precision - len))
	{
		ft_putchar('0', count);
		i++;
	}
	if (params->type == 'x')
		ft_putstr(str, 1000, count);
	else
		ft_putstr(ft_strtoupper(str), 1000, count);
	free(str);
}

void		ft_handle_x(t_params *params, va_list *ap, int *count)
{
	unsigned int	value;

	value = va_arg(*ap, unsigned int);
	if (value == 0 && params->width == 0 && params->isprecision == 0)
	{
		ft_putchar('0', count);
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
