/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:13:47 by ameta             #+#    #+#             */
/*   Updated: 2021/01/10 15:26:31 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

static int	ft_integer_len(long long n)
{
	int count;

	count = 0;
	if (n == 0)
		count++;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	ft_printi_min(t_params *params, int value, int sign, int *count)
{
	int len;
	int i;

	i = 0;
	len = (value != -2147483648) ? ft_integer_len(value)
		: ft_integer_len(value) - 1;
	params->width = (sign) ? params->width - 1 : params->width;
	if (sign == 1)
		ft_putchar('-', count);
	while (i < (params->precision - len))
	{
		ft_putchar('0', count);
		i++;
	}
	ft_putnbr(value, count);
	while (i < (params->width - len))
	{
		ft_putchar(' ', count);
		i++;
	}
}

static void	ft_prizero(t_params *params, int value, int sign, int *count)
{
	int len;
	int i;

	i = 0;
	len = (value != -2147483648) ? ft_integer_len(value)
		: ft_integer_len(value) - 1;
	params->width = (sign) ? params->width - 1 : params->width;
	params->precision = (params->precision < len) ? len : params->precision;
	while (i < (params->width - params->precision))
	{
		if (params->isprecision == 0)
			ft_putchar('0', count);
		else
			ft_putchar(' ', count);
		i++;
	}
	i = ft_integer_len(value);
	if (sign == 1)
		ft_putchar('-', count);
	while (i < (params->precision))
	{
		ft_putchar('0', count);
		i++;
	}
	ft_putnbr(value, count);
}

static void	ft_printi_noflags(t_params *params, int value, int sign, int *count)
{
	int len;
	int reset;
	int i;

	i = 0;
	len = (value != -2147483648) ? ft_integer_len(value)
		: ft_integer_len(value) - 1;
	reset = (params->precision > len) ? params->precision - len : 0;
	params->width = (sign) ? params->width - 1 : params->width;
	while (i < (params->width - len - reset))
	{
		ft_putchar(' ', count);
		i++;
	}
	i = 0;
	if (sign == 1)
		ft_putchar('-', count);
	while (i < (params->precision - len))
	{
		ft_putchar('0', count);
		i++;
	}
	ft_putnbr(value, count);
}

void		ft_handle_i(t_params *params, va_list *ap, int *count, int sign)
{
	int value;

	value = va_arg(*ap, int);
	if (params->isprecision == 1 && params->precision == 0 && value == 0)
	{
		ft_print_zero(params, count);
		return ;
	}
	if (value < 0)
	{
		value = value * -1;
		sign = 1;
		if (((params->width < ft_integer_len(value)) && params->precision == 0)
			|| (params->flag_zero && params->isprecision == 0))
		{
			ft_putchar('-', count);
			sign = 2;
		}
	}
	if (params->flag_minus)
		ft_printi_min(params, value, sign, count);
	else if (params->flag_zero)
		ft_prizero(params, value, sign, count);
	else
		ft_printi_noflags(params, value, sign, count);
}
