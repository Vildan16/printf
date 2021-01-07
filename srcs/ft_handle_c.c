//
// Created by ameta on 07.01.2021.
//

#include "ft_header.h"

void	ft_handle_c(t_params params, va_list *ap, int *count)
{
	int arg;
	int len;

	arg = va_arg(*ap, int);
	len = 1;
	*count += len;
	if (!params.flag_minus && params.width >= len)
	{
		while (params.width > len)
		{
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
	ft_putchar((char)arg);
	if (params.flag_minus && params.width >= len)
	{
		while (params.width > len)
		{
			ft_putchar(' ');
			*count += 1;
			len++;
		}
	}
}