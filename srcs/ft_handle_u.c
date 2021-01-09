//
// Created by Anneliese Meta on 1/9/21.
//

#include "ft_header.h"

void	ft_handle_u(t_params params, va_list *ap, int *count)
{
	int 			len;
	unsigned int	arg;
	char 			*str;

	arg = va_arg(*ap, unsigned int);
	arg = (unsigned int)(4294967295 + 1 + arg);
	str = ft_itoa_u(arg);
	if (params.precision <= (int)ft_strlen(ft_itoa(arg)))
		len = ft_strlen(str);
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
