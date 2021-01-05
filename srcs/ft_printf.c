//
// Created by ameta on 05.01.2021.
//

#include <stdarg.h>
#include <unistd.h>

int		ft_atoi(const char *nptr) //LIBFT
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char 	ft_get_type(const char *fmt)
{
	int	i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == 'i' || fmt[i] == 'd')
			return('i');
		if (fmt[i] == 'c')
			return('c');
		if (fmt[i] == 's')
			return('s');
		if (fmt[i] == 'p')
			return('p');
		if (fmt[i] == 'x')
			return('x');
		if (fmt[i] == 'x')
			return('X');
		if (fmt[i] == '%')
			return('%');
		i++;
	}
}

void	ft_get_flags(const char *fmt, int *flag_zero, int *flag_minus)
{
	*flag_zero = 0;
	*flag_minus = 0;
	while (*fmt == '-' || *fmt == '0')
	{
		if (*fmt == '0')
			*flag_zero = 1;
		if (*fmt == '-')
			*flag_minus = 1;
		fmt++;
	}
}

int		ft_get_width(const char *fmt, va_list ap)
{
	int		result;

	result = -1;
	if (*fmt >= '0' && *fmt <= '9')
		result = ft_atoi(fmt);
	if (*fmt == '*')
		result = va_arg(ap, int);
	while ((*fmt >= '0' && *fmt <= '9') || *fmt == '*')
		fmt++;
	return(result);
}

int		ft_get_precision(const char *fmt, va_list ap)
{
	int		result;

	result = -1;
	if (*fmt == '.')
	{
		result = 0;
		fmt++;
		if (*fmt >= '0' && *fmt <= '9')
			result = ft_atoi(fmt);
		if (*fmt == '*')
			result = va_arg(ap, int);
		while ((*fmt >= '0' && *fmt <= '9') || *fmt == '*')
			fmt++;
	}
	return(result);
}

void 	ft_handle(const char *fmt, va_list ap)
{
	int		flag_zero;
	int		flag_minus;
	int		width;
	int 	precision;
	char 	type;

	type = ft_get_type(fmt);
	ft_get_flags(fmt, &flag_zero, &flag_minus);
	width = ft_get_width(fmt, &ap);
	precision = ft_get_precision(fmt, &ap);
}

int		ft_printf(const char *fmt, ...)
{
	va_list ap;
	int 	i;
	int 	count;

	count = 0;
	i = 0;
	va_start(ap, fmt);
	while(*fmt)
	{
		if (*fmt == '%')
			ft_handle(++fmt, &ap);
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

int		main(void)
{
	ft_printf("abcd");
	return (0);
}
