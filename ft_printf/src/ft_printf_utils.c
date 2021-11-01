#include "ft_printf.h"

void	ft_putnbr(int n, int *char_written)
{
	unsigned int    nb;

	if (n < 0)
	{
		nb = (unsigned int)(-1 * n);
		ft_putchar_count('-', char_written);
	}
	else
		nb = (unsigned int)n;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, char_written);
		ft_putnbr(nb % 10, char_written);
	}
	else
		ft_putchar_count(nb + '0', char_written);
}

void	ft_putnbr_unsigned(unsigned int n, int *char_written)
{
	unsigned int	nb;

	nb = (unsigned int)n;
	if (nb >= 10)
	{
		ft_putnbr_unsigned(nb / 10, char_written);
		ft_putnbr_unsigned(nb % 10, char_written);
	}
	else
			ft_putchar_count(nb + '0', char_written);
}

void	ft_putaddress_ptr(unsigned long n, char *base, int *char_written)
{
	unsigned long	nb;
	size_t			base_size;

	if (*char_written == 0)
		*char_written += ft_nbrlen_hexa(n);
	base_size = ft_strlen(base);
	nb = n;
	if (nb >= (unsigned long)base_size)
	{
		ft_putaddress_ptr(nb / base_size, base, char_written);
		ft_putaddress_ptr(nb % base_size, base, char_written);
	}
	else
			ft_putchar(base[nb]);
}

void	ft_putchar_count(char c, int *char_written)
{
	write(1, &c, 1);
	*char_written += 1;
}
