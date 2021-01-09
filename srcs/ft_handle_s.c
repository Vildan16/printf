//
// Created by ameta on 07.01.2021.
//

#include "ft_header.h"

static void	ft_prints_min(t_params *params, va_list *ap, int *count)
{
	char	*string;
	int		len;
	int		i;

	i = 0;
	string = va_arg(*ap, char*);
	len = (!string) ? 6 : ft_strlen(string);
	len = (params->precision == -1 || len < params->precision) ?
			len : params->precision;
	if (!string)
	{
		ft_putstr("(null)");
		*count += 6;
	}
	else
	{
		ft_putstr(string);
		*count += ft_strlen(string);
	}
	while (i < (params->width - len))
	{
		ft_putchar(' ');
		*count += 1;
		i++;
	}
}

static void	ft_prints_nomin(t_params *params, va_list *ap, int *count)
{
	char	*string;
	int		len;
	int		i;

	i = 0;
	string = va_arg(*ap, char*);
	len = (!string) ? 6 : ft_strlen(string);
	len = (params->precision == -1 || len < params->precision) ?
			len : params->precision;
	while (i < (params->width - len))
	{
		ft_putchar(' ');
		*count += 1;
		i++;
	}
	if (!string)
	{
		ft_putstr("(null)");
		*count += 6;
	}
	else
	{
		ft_putstr(string);
		*count += ft_strlen(string);
	}
}

void	ft_handle_s(t_params *params, va_list *ap, int *count)
{
	if (params->precision == 0 && params->width == 0)
	return ;
	if (params->flag_minus == 1)
		ft_prints_min(params, ap, count);
	else
		ft_prints_nomin(params, ap, count);
}
