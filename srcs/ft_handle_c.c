//
// Created by ameta on 07.01.2021.
//

#include "ft_header.h"

static void	ft_printc_min(t_params *params, va_list *ap, int *count)
{
	int chr;
	int i;

	i = 0;
	chr = va_arg(*ap, int);
	ft_putchar((char)chr);
	*(count) += 1;
	while (i < (params->width - 1))
	{
		ft_putchar(' ');
		*(count) += 1;
		i++;
	}
}

static void	ft_printc_nomin(t_params *params, va_list *ap, int *count)
{
	int chr;
	int i;

	i = 0;
	chr = va_arg(*ap, int);
	while (i < (params->width - 1))
	{
		ft_putchar(' ');
		*(count) += 1;
		i++;
	}
	ft_putchar((char)chr);
	*(count) += 1;
}

void	ft_handle_c(t_params *params, va_list *ap, int *count)
{
	if (params->flag_minus == 1)
		ft_printc_min(params, ap, count);
	else
		ft_printc_nomin(params, ap, count);
}
