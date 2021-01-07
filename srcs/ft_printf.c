//
// Created by ameta on 05.01.2021.
//

#include "ft_header.h"

int		ft_printf(const char *fmt, ...)
{
	va_list ap;
	int 	count;

	count = 0;
	va_start(ap, fmt);
	while(*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (!ft_handle(&fmt, &ap, &count))
				return(-1);
		}
		else
		{
			ft_putchar(*fmt);
			count++;
		}
		fmt++;
	}
	va_end(ap);
	return(count);
}