#include "ft_printf.h"

void	ft_putnbr(int n)
{
	unsigned int    nb;

	if (n < 0)
	{
		nb = (unsigned int)(-1 * n);
		ft_putchar('-');
	}
	else
		nb = (unsigned int)n;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
			ft_putchar(nb + '0');
}

void	ft_putnbr_unsigned(unsigned int n)
{
	unsigned int	nb;

	if (!n)
		return ;
	nb = (unsigned int)n;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
			ft_putchar(nb + '0');
}
