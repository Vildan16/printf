//
// Created by ameta on 05.01.2021.
//

#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void 	ft_handle(const char *fmt)
{

}

int		ft_printf(const char *fmt, ...)
{
	va_list ap;
	int 	i;

	i = 0;
	va_start(ap, fmt);
	while(*fmt)
	{
		if (*fmt == '%')
			ft_handle(++fmt);
		else
			ft_putchar(*fmt);
		fmt++;
	}
	va_end(ap);
}

int		main(void)
{
	ft_printf("abcd");
	return (0);
}