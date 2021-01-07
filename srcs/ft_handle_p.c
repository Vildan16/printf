//
// Created by ameta on 07.01.2021.
//

#include "ft_header.h"

void	ft_handle_p(t_params params, va_list *ap, int *count)
{
	int						len;
	unsigned long long int	arg;
	char					*str;

	arg = va_arg(*ap, unsigned long long int);
	str = ft_itoa_hex(arg);
	len = (int)ft_strlen(str) + 2;
	*count = *count + len;
	ft_print_width(params, &len, count);
	ft_putstr("0x");
	ft_putstr(ft_strtolower(str));
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
