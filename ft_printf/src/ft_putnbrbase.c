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

void	ft_putnbrbase(int nb, char *base, int *char_written)
{
	int	base_size;

	if (*char_written == 0)
		*char_written += ft_nbrlen_hexa((unsigned long)nb);
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	base_size = ft_strlen(base);
	if (nb >= base_size)
	{
		ft_putnbrbase(nb / base_size, base, char_written);
		ft_putnbrbase(nb % base_size, base, char_written);
	}
	else
		ft_putchar(base[nb]);
}
