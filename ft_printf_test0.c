#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

typedef struct s_params
{
    int width;
    int isprecision;
    int precision;
    char type;
}               t_params;

void    ft_putchar(char c, int *count)
{
    write(1, &c, 1);
    *count += 1;
}

int     ft_get_width(const char **fmt)
{
    int w = 0;
    while (**fmt >= '0' && **fmt <= '9')
    {
        w = w * 10 + (**fmt - '0');
        *fmt += 1;
    }
    return (w);
}

void    ft_get_precision(const char **fmt, int *p, int *isp)
{
    *p = 0;
    *isp = 0;
    int flag = 1;

    if (**fmt == '.')
    {
        *isp = 1;
        *fmt += 1;
        while (**fmt >= '0' && **fmt <= '9')
        {
            *p = *p * 10 + (**fmt - '0');
            *fmt += 1;
        }
    }
}

char    ft_get_type(const char **fmt)
{
    char c = '0';
    if (**fmt == 'd')
        c = 'd';
    else if (**fmt == 's')
        c = 's';
    else if (**fmt == 'x')
        c = 'x';
    return (c);
}

void    ft_get_params(const char **fmt, t_params *params)
{
    params->width = ft_get_width(fmt);
    ft_get_precision(fmt, &params->precision, &params->precision);
    params->type = ft_get_type(fmt);
}

void    ft_print_zero(t_params *params, int *count)
{
    int i = 0;

    while (i < params->width)
    {
        ft_putchar(' ', count);
        i++;
    }
}

int     ft_int_len(long long a)
{
    int res = 0;
    if (a == 0)
        res++;
    if (a < 0)
        res++;
    while (a != 0)
    {
        a = a / 10;
        res++;
    }
    return (res);
}

void    ft_putnbr(long a, int *count)
{
    char c[15];
    int i = 0;

    if (a == 0)
        ft_putchar('0', count);
    else if (a == INT_MIN)
    {
        ft_putchar('2', count);
        a = 147483648;
    }
    while (a != 0)
    {
        c[i] = a % 10 + '0';
        a = a / 10;
        i++;
    }
    while (--i >= 0)
        ft_putchar(c[i], count);
}

void    ft_print_d(t_params *params, int value, int *count, int sign)
{
    int len;
    int reset;
    int i;

    i = 0;
    len = (value != INT_MIN) ? ft_int_len(value) : ft_int_len(value) - 1;
    reset = (params->precision > len) ? params->precision - len : 0;
    if (sign)
        params->width -= 1;
    while (i < params->width - len - reset)
    {
        ft_putchar(' ', count);
        i++;
    } 
    i = 0;
    if (sign == 1)
        ft_putchar('-', count);
    while (i < params->precision - len)
    {
        ft_putchar('0', count);
        i++;
    }
    ft_putnbr(value, count);
}

void    ft_handle_d(t_params *params, va_list *ap, int *count, int sign)
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
        sign = 1;
        value *= -1;
        if (params->width < ft_int_len(value) && params->precision == 0)
        {
            ft_putchar('-', count);
            sign = 2;
        }
    }
    ft_print_d(params, value, count, sign);
}

void    ft_printx(t_params *params, unsigned int value, int *count)
{
    char *str;
    int     i = 0;
    int len;

    str = ft_itoa_hex(value);
    len = ft_strlen(str);
    params->precision = (params->precision < len) ? len : params->precision;
    while (i < params->width - params->precision)
    {
        ft_putchar(' ', count);
        i++;
    }
    i = 0;
    while (i < params->precision - len)
    {
        ft_putchar('0', count);
        i++;
    }
    ft_putstr(str);
    free(str);
}

void    ft_handle_x(t_params *params, va_list *ap, int *count)
{
    unsigned int a;

    a = va_arg(*ap, unsigned int);
    if (params->isprecision == 1 && params->precision == 0 && a == 0)
    {
        ft_print_zero(params, count);
        return ;
    }
    ft_printx(params, a, count);
}

void    ft_handle_s(t_params *params, va_list *ap, int *count)
{
    char *str;
    int len;
    int i = 0;

    str = va_arg(*ap, char*);
    len = (!str) ? 6 : ft_strlen(str);
    len = (params->isprecision == 0 || len < params->precision) ? len : params->precision;
    while (i < (params->width - len))
    {
        ft_putchar(' ', count);
        i++;
    }
    if (!str)
        ft_putstr("(null)", len, count);
    else
        ft_putstr(str, len, count);
}

int     ft_handle(const char **fmt, va_list *ap, int *count)
{
    t_params params;

    ft_get_params(fmt, &params);
    if (params.type == '0')
        return (0);
    else if (params.type == 'd')
        ft_handle_d(&params, fmt, ap, count, 0);
    else if (params.type == 's')
        ft_handle_d(&params, fmt, ap, count);
    else if (params.type == 'x')
        ft_handle_d(&params, fmt, ap, count);
    return (1);
}

int     ft_printf(const char *fmt, ...)
{
    int count;
    va_list ap;

    if (!fmt || !fmt[0])
        return (0);
    va_start(ap, fmt);
    count = 0;
    while(*fmt)
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
    va_close(ap);
    return (count);
}