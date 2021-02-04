/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_exam.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:46:48 by ameta             #+#    #+#             */
/*   Updated: 2021/02/04 12:19:37 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

typedef struct	s_params
{
	int			width;
	int			precision;
	int			isprecision;
	char		type;
}				t_params;

static void ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

static int ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void		ft_putnbr(int n, int *count)
{
	int		i;
	char	a[15];

	i = 0;
	if (n == 0)
		ft_putchar('0', count);
	if (n == -2147483648)
	{
		ft_putchar('2', count);
		n = 147483648;
	}
	if (n < 0)
	{
		n = -1 * n;
	}
	while (n != 0)
	{
		a[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar(a[i], count);
}


static int		ft_atoi(const char *nptr)
{
	int i;
	int res;
	int minus;

	i = 0;
	res = 0;
	minus = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n' || \
			nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-')
	{
		minus = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * minus);
}

static int		ft_get_width(const char **fmt, va_list *ap)
{
	int		result;

	result = 0;
	if (**fmt >= '0' && **fmt <= '9')
		result = ft_atoi(*fmt);
	while (**fmt >= '0' && **fmt <= '9')
		*fmt += 1;
	return (result);
}

static void	ft_get_precision(const char **fmt, va_list *ap, int *precision, int *isprecision)
{
	*precision = 0;
	*isprecision = 0;
	if (**fmt == '.')
	{
		*isprecision = 1;
		*fmt += 1;
		if (**fmt >= '0' && **fmt <= '9')
			*precision = ft_atoi(*fmt);
		else if (**fmt == '*')
			*precision = va_arg(*ap, int);
		while ((**fmt >= '0' && **fmt <= '9') || **fmt == '*' || **fmt == '-')
			*fmt += 1;
	}
}

static char	ft_get_type(const char *fmt)
{
	char	result;

	result = '0';
	if (*fmt == 'd')
		result = 'd';
	else if (*fmt == 's')
		result = 's';
	else if (*fmt == 'x')
		result = 'x';
	return (result);
}

static void	ft_get_params(const char **fmt, va_list *ap, t_params *params)
{
	params->width = ft_get_width(fmt, ap);
	ft_get_precision(fmt, ap, &params->precision, &params->isprecision);
	params->type = ft_get_type(*fmt);
	if (params->precision < 0)
	{
		params->isprecision = 0;
		params->precision = 0;
	}
}

void	ft_print_zero(t_params *params, int *count)
{
	int i;

	i = 0;
	while (i < params->width)
	{
		ft_putchar(' ', count);
		i++;
	}
}

static int	ft_integer_len(long long n)
{
	int count;

	count = 0;
	if (n == 0)
		count++;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	ft_printi_noflags(t_params *params, int value, int sign, int *count)
{
	int len;
	int reset;
	int i;

	i = 0;
	len = (value != -2147483648) ? ft_integer_len(value)
		: ft_integer_len(value) - 1;
	reset = (params->precision > len) ? params->precision - len : 0;
	params->width = (sign) ? params->width - 1 : params->width;
	while (i < (params->width - len - reset))
	{
		ft_putchar(' ', count);
		i++;
	}
	i = 0;
	if (sign == 1)
		ft_putchar('-', count);
	while (i < (params->precision - len))
	{
		ft_putchar('0', count);
		i++;
	}
	ft_putnbr(value, count);
}

static void		ft_handle_d(t_params *params, va_list *ap, int *count, int sign)
{
	int value;

	value = va_arg(*ap, int);
	if (params->isprecision == 1 && params->precision == 0 && value == 0)
	{
		ft_print_zero(params, count);
		return ;
	}
	if (value < 0)
	{
		value = value * -1;
		sign = 1;
		if ((params->width < ft_integer_len(value)) && params->precision == 0)
		{
			ft_putchar('-', count);
			sign = 2;
		}
	}
    ft_printi_noflags(params, value, sign, count);
}

void	ft_putstr(char *s, int size, int *count)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] && i < size)
	{
		ft_putchar(s[i], count);
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
	len = (params->isprecision == 0 || len < params->precision) ?
			len : params->precision;
	while (i < (params->width - len))
	{
		ft_putchar(' ', count);
		i++;
	}
	if (!string)
		ft_putstr("(null)", len, count);
	else
		ft_putstr(string, len, count);
}

static void		ft_handle_s(t_params *params, va_list *ap, int *count)
{
	ft_prints_nomin(params, ap, count);
}

static int	ft_nn(unsigned long value)
{
	int	number;

	if (value == 0)
		return (1);
	number = 0;
	while (value != 0)
	{
		number++;
		value = value / 16;
	}
	return (number);
}

static char		*ft_itoa_hex(unsigned long value)
{
	unsigned int	division;
	char			*hex;
	int				number;
	int				nn;

	nn = ft_nn(value);
	hex = (char *)malloc(sizeof(char) * (nn + 1));
	if (value == 0)
		hex[0] = '0';
	number = 0;
	while (value != 0)
	{
		division = value % 16;
		if (division < 10)
			hex[nn - number - 1] = 48 + division;
		else
			hex[nn - number - 1] = 87 + division;
		number++;
		value = value / 16;
	}
	hex[nn] = '\0';
	return (hex);
}


static void	ft_printx_noflags(t_params *params, unsigned int value, int *count)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa_hex(value);
	len = ft_strlen(str);
	params->precision = (params->precision < len) ? len :
							params->precision;
	while (i < (params->width - params->precision))
	{
		ft_putchar(' ', count);
		i++;
	}
	i = 0;
	while (i < (params->precision - len))
	{
		ft_putchar('0', count);
		i++;
	}
	ft_putstr(str, 1000, count);
	free(str);
}

static void		ft_handle_x(t_params *params, va_list *ap, int *count)
{
	unsigned int	value;

	value = va_arg(*ap, unsigned int);
	if (params->isprecision == 1 && params->precision == 0 && value == 0)
	{
		ft_print_zero(params, count);
		return ;
	}
	ft_printx_noflags(params, value, count);
}

static int  ft_handle(const char **fmt, va_list *ap, int *count)
{
	t_params params;

	ft_get_params(fmt, ap, &params);
	if (params.type == '0')
		return (0);
	if (params.type == 'd')
		ft_handle_d(&params, ap, count, 0);
	else if (params.type == 's')
		ft_handle_s(&params, ap, count);
	else if (params.type == 'x')
		ft_handle_x(&params, ap, count);
	return (1);
}



int		    ft_printf(const char *fmt, ...)
{
	va_list ap;
	int		count;

	if (!fmt || !fmt[0])
		return (0);
	count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (!ft_handle(&fmt, &ap, &count))
				return (-1);
		}
		else
			ft_putchar(*fmt, &count);
		fmt++;
	}
	va_end(ap);
	return (count);
}

int		main(void)
{
	int a = 12345;

	int ac = printf("A| %.1x\n", a);
	int bc = ft_printf("B| %.1x\n", a);
	printf("[%d][%d]", ac, bc);
}