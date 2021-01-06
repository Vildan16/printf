//
// Created by ameta on 05.01.2021.
//

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>  //remove
#include <stdlib.h>  //remove

typedef struct		s_params
{
	int				flag_zero;
	int				flag_minus;
	int				width;
	int 			precision;
	char 			type;
}					t_params;



size_t	ft_strlen(const char *s)  //LIBFT
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_check_minint(int n, char *str)  //LIBFT
{
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	return (n);
}

static int	ft_nn(int n)  //LIBFT
{
	int		nn;

	nn = 0;
	if (n == -2147483648)
		return (11);
	if (n <= 0)
	{
		nn++;
		n = -1 * n;
	}
	while (n != 0)
	{
		n = n / 10;
		nn++;
	}
	return (nn);
}

char		*ft_itoa(int n)   //LIBFT
{
	int		nn;
	char	*str;

	nn = ft_nn(n);
	str = (char *)malloc(sizeof(char) * (nn + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[nn - 1] = '0';
	str[nn] = '\0';
	n = ft_check_minint(n, str);
	if (n < 0)
	{
		str[0] = '-';
		n = -1 * n;
	}
	while (n != 0)
	{
		str[nn - 1] = n % 10 + '0';
		n = n / 10;
		nn--;
	}
	return (str);
}

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

int		ft_get_width(const char **fmt, va_list *ap)
{
	int		result;

	result = -1;
	if (**fmt >= '0' && **fmt <= '9')
		result = ft_atoi(*fmt);
	if (**fmt == '*')
		result = va_arg(*ap, int);
	while ((**fmt >= '0' && **fmt <= '9') || **fmt == '*')
		*fmt += 1;
	return(result);
}

int		ft_get_precision(const char **fmt, va_list *ap)
{
	int		result;

	result = -1;
	if (**fmt == '.')
	{
		*fmt += 1;
		if (**fmt >= '0' && **fmt <= '9')
			result = ft_atoi(*fmt);
		else if (**fmt == '*')
			result = va_arg(*ap, int);
		else
			result = -1;
		while ((**fmt >= '0' && **fmt <= '9') || **fmt == '*' || **fmt == '-')
			*fmt += 1;
	}
	return(result);
}

static void		ft_putnbr(int n)
{
	int		i;
	char	a[15];

	i = 0;
	if (n == 0)
		ft_putchar('0');
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -1 * n;
	}
	while (n != 0)
	{
		a[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar(a[i]);
}

void	ft_handle_i(t_params params, va_list *ap)
{
	int len;
	int arg;

	arg = va_arg(*ap, int);
	len = ft_strlen(ft_itoa(arg));
	if (params.precision != -1)
		params.flag_zero = 0;
	if (!params.flag_minus && params.width >= len)
	{
		while (params.width > len)
		{
			if (params.flag_zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			len++;
		}
	}
	if (params.precision != -1)
	{
		while (params.precision > len)
		{
			ft_putchar('0');
			len++;
		}
	}
	ft_putnbr(arg);
}

int		ft_handle(const char **fmt, va_list *ap)
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
			if (!ft_handle(&fmt, &ap))
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
	int a;
	int b;

	a = 555;
	b = 111;
	printf("a = %-7d\n", a);
	ft_printf("b = %-7d\n", b);
	return (0);
}
