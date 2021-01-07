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
	len = (int)ft_strlen(str);
	*count += len;
	if (params.precision != -1 || params.flag_minus)
		params.flag_zero = 0;
	ft_print_width(params, &len, count, 1);
	if (params.precision != -1)
	{
		while (params.precision > len)
		{
			ft_putchar('0');
			*count += 1;
			len++;
		}
	}
	if (params.type == 'x')
		ft_putstr(ft_strtolower(str));
	else
		ft_putstr(str);
	ft_print_width(params, &len, count, 2);
}
