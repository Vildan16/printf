//
// Created by ameta on 07.01.2021.
//

#include "ft_header.h"

int		ft_handle_c(t_params params, va_list *ap, int *count)
{
	int arg;
	int len;

	if (params.precision != -1 || params.flag_minus)
		return (0);
	arg = va_arg(*ap, int);
	len = 1;
	*count += len;
	if (!params.flag_minus && params.width >= len)
	{
		while (params.width > len)
		{
			ft_putchar(' ');
			*count += 1;
			params.width--;
		}
	}
	ft_putchar((char)arg);
	if (params.flag_minus)
	{
		while (params.width > len)
		{
			ft_putchar(' ');
			*count += 1;
			params.width--;
		}
	}
	return (1);
}
