//
// Created by ameta on 07.01.2021.
//

#include "ft_header.h"

void	ft_print_width(t_params params, int *len, int *count, int a)
{
	if (!params.flag_minus && params.width >= *len && \
	params.width > params.precision && a == 1)
	{
		while (params.width > *len)
		{
			if (params.flag_zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			*count += 1;
			(*len)++;
		}
		a = 1;
	}
	if (a == 2)
	{
		while (params.width > *len)
		{
			if (params.flag_zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			*count += 1;
			(*len)++;
		}
	}
}
