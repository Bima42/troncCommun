#include "ft_printf.h"

/*static	int	ft_nbrlen(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}*/

void	ft_putnbrbase(int nb, char *base)
{
//	int	len_nb;
	int	base_size;

//	len_nb = ft_nbrlen(nb);
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	base_size = ft_strlen(base);
	if (nb >= base_size)
	{
		ft_putnbrbase(nb / base_size, base);
		ft_putnbrbase(nb % base_size, base);
	}
	else
		ft_putchar(base[nb]);
}
