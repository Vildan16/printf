d:
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


s:
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



x:
unsigned int a;

    a = va_arg(*ap, unsigned int);
    if (params->isprecision == 1 && params->precision == 0 && a == 0)
    {
        ft_print_zero(params, count);
        return ;
    }
    ft_printx(params, a, count);

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

