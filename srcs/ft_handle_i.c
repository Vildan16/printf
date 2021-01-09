//
// Created by ameta on 07.01.2021.
//

#include "ft_header.h"

void	ft_handle_i(t_params params, va_list *ap, int *count)
{
	int len;
	int arg;

	arg = va_arg(*ap, int);
	if (params.precision <= (int)ft_strlen(ft_itoa(arg)))
		len = ft_strlen(ft_itoa(arg));
	else
		len = params.precision;
	*count += len;
	if (params.precision != -1 || params.flag_minus)
		params.flag_zero = 0;
	if (arg < 0 && (params.flag_minus || params.flag_zero || \
	params.precision > (int)ft_strlen(ft_itoa(arg))))
	{
		ft_putchar('-');
		arg *= -1;
		*count += 1;
	}
	if (!params.flag_minus && params.width >= len)
	{
		while (params.width > len)
		{
			if (params.flag_zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			*count += 1;
			params.width--;
		}
	}
	while (params.precision > (int)ft_strlen(ft_itoa(arg)))
	{
		ft_putchar('0');
		params.precision--;
	}
	ft_putnbr(arg);
	if (params.flag_minus)
	{
		while (params.width > len)
		{
			if (params.flag_zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			*count += 1;
			params.width--;
		}
	}
}
