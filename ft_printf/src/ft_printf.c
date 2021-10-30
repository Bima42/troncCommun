#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	count_args;
	int		count;

	va_start(count_args, str);
	count = 0;
	while (*str != '\0')
	{
		if (ft_isprint(*str) && *str != '%')
			ft_putchar(*str);
		count++;
		str++;
	}
	va_end(count_args);
	return (count);
}
