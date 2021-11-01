#include "ft_printf.h"

int	ft_nbrlen_hexa(unsigned long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		count++;
	while (nb > 0)
	{
		nb = nb / 16;
		count++;
	}
	return (count);
}

void	ft_putnbrbase(long unsigned int nb, char *base, int *char_written)
{
	size_t	base_size;

	if (*char_written == 0)
		*char_written += ft_nbrlen_hexa(nb);
/*	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}*/
	base_size = ft_strlen(base);
	if (nb >= base_size)
	{
		ft_putnbrbase(nb / base_size, base, char_written);
		ft_putnbrbase(nb % base_size, base, char_written);
	}
	else
		ft_putchar(base[nb]);
}

void   ft_putnbr(int n, int *char_written)
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

void    ft_putnbr_unsigned(unsigned int n, int *char_written)
{
        unsigned int    nb;

        nb = (unsigned int)n;
        if (nb >= 10)
        {
			ft_putnbr_unsigned(nb / 10, char_written);
			ft_putnbr_unsigned(nb % 10, char_written);
        }
        else
			ft_putchar_count(nb + '0', char_written);
}
