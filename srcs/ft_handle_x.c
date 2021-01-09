//
// Created by ameta on 07.01.2021.
//

#include "ft_header.h"

void	ft_handle_x(t_params params, va_list *ap, int *count)
{
	int				len;
	unsigned int	arg;
	char			*str;

	arg = va_arg(*ap, unsigned int);
	str = ft_itoa_hex(arg);
	if (params.precision <= (int)ft_strlen(str))
		len = (int)ft_strlen(str);
	else
		len = params.precision;
	*count += len;
	if (params.flag_minus)
		params.flag_zero = 0;
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
	while (params.precision > (int)ft_strlen(str))
	{
		ft_putchar('0');
		params.precision--;
	}
	if (params.type == 'x')
		ft_putstr(ft_strtolower(str));
	else
		ft_putstr(str);
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
