//
// Created by ameta on 07.01.2021.
//

#include "ft_header.h"

void	ft_handle_i(t_params params, va_list *ap, int *count) //fixme 43 lines
{
	int len;
	int arg;

	arg = va_arg(*ap, int);
	len = ft_strlen(ft_itoa(arg));
	*count += len;
	if (params.precision != -1 || params.flag_minus)
		params.flag_zero = 0;
	if (!params.flag_minus && params.width >= len && \
	params.width > params.precision)
	{
		while (params.width > len)
		{
			if (params.flag_zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			*count += 1;
			len++;
		}
	}
	if (params.precision != -1)
	{
		while (params.precision > len)
		{
			ft_putchar('0');
			*count += 1;
			len++;
		}
	}
	ft_putnbr(arg);
	if (params.flag_minus && params.width >= len)
	{
		while (params.width > len)
		{
			if (params.flag_zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			*count += 1;
			len++;
		}
	}
}
