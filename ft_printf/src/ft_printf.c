#include "ft_printf.h"

static int	detection_type(va_list count_args, const char *str, int count);
static void ft_putstr(const char *str, int *count);
static void ft_get_address_ptr(void *ptr, int *char_written);
static int	ft_count_ret(const char *str);

static void ft_get_address_ptr(void *ptr, int *char_written)
{
	unsigned long nb;

	nb = (unsigned long)ptr;
	write(1, "0x", 2);
	ft_putaddress_ptr(nb, BASE_HEXA, char_written);
	*char_written += 1;
}

static void ft_putstr(const char *str, int *count)
{
	while (*str)
	{
		ft_putchar(*str);
		*count += 1;
		str++;
	}
}

static int	detection_type(va_list count_args, const char *str, int count)
{
	int	char_written;

	char_written = 0;
	if (str[count] == PURCENT)
		ft_putchar_count(PURCENT, &char_written);
	else if (str[count] == CHAR)
		ft_putchar_count(va_arg(count_args, int), &char_written);
	else if (str[count] == STRING)
		ft_putstr(va_arg(count_args, char *), &char_written);
	else if (str[count] == INT)
		ft_putnbr(va_arg(count_args, int), &char_written);
	else if (str[count] == DOUBLE)
		ft_putnbr(va_arg(count_args, int), &char_written);
	else if (str[count] == UNSIGNED)
		ft_putnbr(va_arg(count_args, unsigned int), &char_written);
	else if (str[count] == HEXA)
		ft_putnbrbase(va_arg(count_args, unsigned int), BASE_HEXA, &char_written);
	else if (str[count] == POINTER)
		ft_get_address_ptr(va_arg(count_args, void *), &char_written);
	return (char_written);
}

static int	ft_count_ret(const char *str)
{
	int	i;
	int	count_purcent;
	int	count_double_purcent;

	i = 0;
	count_purcent = 0;
	count_double_purcent = 0;
	while (str[i] != '\0')
	{
		if (str[i] == PURCENT && str[i + 1] == PURCENT)
			count_double_purcent++;
		else if (str[i] == PURCENT && str[i + 1] != PURCENT)
			count_purcent++;
		i++;
	}
	i -= (2 * count_purcent);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	count_args;
	int		count;
	int		count_ret;

	va_start(count_args, str);
	count = 0;
	count_ret = ft_count_ret(str);
	while (str[count] != '\0')
	{
		if (str[count] == '%')
			count_ret += detection_type(count_args, str, ++count);
		else
			ft_putchar(str[count]);
		count++;
	}
	va_end(count_args);
	return (count_ret);
}
