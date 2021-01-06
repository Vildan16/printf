//
// Created by ameta on 05.01.2021.
//

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>  //remove

typedef struct		s_params
{
	int				flag_zero;
	int				flag_minus;
	int				width;
	int 			precision;
	char 			type;
}					t_params;

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
	char 	result;

	result = '0';
	if (*fmt == 'i' || *fmt == 'd')
		result = 'i';
	else if (*fmt == 'c')
		result = 'c';
	else if (*fmt == 's')
		result = 's';
	else if (*fmt == 'p')
		result = 'p';
	else if (*fmt == 'x')
		result = 'x';
	else if (*fmt == 'X')
		result = 'X';
	else if (*fmt == '%')
		result = '%';
	return(result);
}

void	ft_get_flags(const char **fmt, int *flag_zero, int *flag_minus)
{
	*flag_zero = 0;
	*flag_minus = 0;

	while (**fmt == '-' || **fmt == '0')
	{
		if (**fmt == '0')
			*flag_zero = 1;
		if (**fmt == '-')
			*flag_minus = 1;
		*fmt += 1;
	}
}

int		ft_get_width(const char **fmt, va_list ap)
{
	int		result;

	result = -1;
	if (**fmt >= '0' && **fmt <= '9')
		result = ft_atoi(*fmt);
	if (**fmt == '*')
		result = va_arg(ap, int);
	while ((**fmt >= '0' && **fmt <= '9') || **fmt == '*')
		*fmt += 1;
	return(result);
}

int		ft_get_precision(const char **fmt, va_list ap)
{
	int		result;

	result = -1;
	if (**fmt == '.')
	{
		result = 0;
		*fmt += 1;
		if (**fmt >= '0' && **fmt <= '9')
			result = ft_atoi(*fmt);
		if (**fmt == '*')
			result = va_arg(ap, int);
		while ((**fmt >= '0' && **fmt <= '9') || **fmt == '*')
			*fmt += 1;
	}
	return(result);
}

void	ft_handle_i(t_params params, va_list ap)
{
	ft_putchar('A');
}

int		ft_handle(const char **fmt, va_list ap)
{
	t_params params;

	ft_get_flags(fmt, &params.flag_zero, &params.flag_minus);
	params.width = ft_get_width(fmt, ap);
	params.precision = ft_get_precision(fmt, ap);
	params.type = ft_get_type(*fmt);
	if (params.type == '0')
		return(0);
	if (params.type == 'i' || params.type == 'd')
		ft_handle_i(params, ap);

/*	else if (params.type == 'c')
		ft_handle_c(params, &ap);
	else if (params.type == 's')
		ft_handle_s(params, &ap);
	else if (params.type == 'p')
		ft_handle_p(params, &ap);
	else if (params.type == 'x')
		ft_handle_x(params, &ap);
	else if (params.type == 'X')
		ft_handle_X(params, &ap);
	else if (params.type == '%')
		ft_handle_percent(params, &ap);*/
	return (1);
}

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
			if (!ft_handle(&fmt, ap))
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

int		main(void)
{
	ft_printf("d");
	return (0);
}
