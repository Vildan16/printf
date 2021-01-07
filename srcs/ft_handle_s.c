//
// Created by ameta on 07.01.2021.
//

#include "ft_header.h"

void	ft_handle_s(t_params params, va_list *ap, int *count)
{
	int		len;
	char	*arg;
	int 	i;

	i = 0;
	arg = va_arg(*ap, char*);
	if ((int)ft_strlen(arg) <= params.precision || params.precision == -1)
		len = ft_strlen(arg);
	else
		len = params.precision;
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
	if (params.precision != -1)
	{
		while (i < len)
		{
			ft_putchar(*arg);
			i++;
			arg++;
		}
	}
	else
		ft_putstr(arg);
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