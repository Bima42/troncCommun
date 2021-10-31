#include "ft_printf.h"

static void	detection_type(va_list count_args, const char *str, int *count);
static void ft_putstr(const char *str);

static void ft_putstr(const char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

static void	detection_type(va_list count_args, const char *str, int *count)
{
	*count += 1;
	if (str[*count] == PURCENT)
		ft_putchar(PURCENT);
	else if (str[*count] == CHAR)
		ft_putchar(va_arg(count_args, int));
	else if (str[*count] == STRING)
		ft_putstr(va_arg(count_args, char *));
	else if (str[*count] == INT)
		ft_putnbr(va_arg(count_args, int));
	else if (str[*count] == DOUBLE)
		ft_putnbr(va_arg(count_args, int));
	else if (str[*count] == UNSIGNED)
		ft_putnbr(va_arg(count_args, unsigned int));
	else if (str[*count] == HEXA)
		ft_putnbrbase(va_arg(count_args, unsigned int), "0123456789abcdef");
	else if (str[*count] == POINTER)
		ft_putstr(va_arg(count_args, void *));
//	else if (str[*count] == 'p')
}

int	ft_printf(const char *str, ...)
{
	va_list	count_args;
	int		count;

	va_start(count_args, str);
	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] == '%')
			detection_type(count_args, str, &count);
		else
			ft_putchar(str[count]);
		count++;
	}
	va_end(count_args);
	return (count);
}
