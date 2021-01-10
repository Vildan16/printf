/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:14:22 by ameta             #+#    #+#             */
/*   Updated: 2021/01/10 15:21:13 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

static void	ft_putnbru(long long n)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putchar('2');
			n = 147483648;
		}
		else
			n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbru(n / 10);
	}
	ft_putchar('0' + (n % 10));
}

static void	ft_printu_min(t_params *params, unsigned int value, int *count)
{
	int				len;
	int				i;

	i = 0;
	len = ft_strlen(ft_itoa_u(value));
	while (i < (params->precision - len))
	{
		ft_putchar('0');
		*count += 1;
		i++;
	}
	ft_putnbru(value);
	*count += ft_strlen(ft_itoa_u(value));
	while (i < (params->width - len))
	{
		ft_putchar(' ');
		*count += 1;
		i++;
	}
}

static void	ft_printu_zero(t_params *params, unsigned int value, int *count)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(ft_itoa_u(value));
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
	ft_putnbru(value);
	*count += ft_strlen(ft_itoa_u(value));
}

static void	ft_printu_noflags(t_params *params, unsigned int value, int *count)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(ft_itoa_u(value));
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
	ft_putnbru(value);
	*count += ft_strlen(ft_itoa_u(value));
}

void		ft_handle_u(t_params *params, va_list *ap, int *count)
{
	unsigned int	value;

	value = va_arg(*ap, unsigned int);
	if (params->isprecision && params->precision == 0 && value == 0)
	{
		ft_print_zero(params, count);
		return ;
	}
	if (params->flag_minus)
		ft_printu_min(params, value, count);
	else if (params->flag_zero)
		ft_printu_zero(params, value, count);
	else
		ft_printu_noflags(params, value, count);
}
