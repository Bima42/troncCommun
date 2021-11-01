#include "ft_printf.h"

void	ft_putchar_count(char c, int *char_written)
{
	write(1, &c, 1);
	*char_written += 1;
}

int	ft_count_ret(const char *str)
{
        int	i;
        int count_purcent;
        int count_double_purcent;

        i = 0;
        count_purcent = 0;
        count_double_purcent = 0;
        while (str[i] != '\0')
        {
			if (str[i] == PURCENT && str[i + 1] == PURCENT)
			{
				i++;
				count_double_purcent++;
			}
			else if (str[i] == PURCENT)
				count_purcent++;
			i++;
        }
        i -= (2 * count_purcent) + (2 * count_double_purcent);
        return (i);
}

void	ft_putstr(const char *str, int *count)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar_count(str[i], count);
		//*count += 1;
		i++;
	}
}

void	ft_get_address_ptr(void *ptr, int *char_written)
{
	if	((long long)ptr == 0)
	{
		write(1, "(nil)", 5);
		*char_written += 5;
		return ;
	}
	else
	{
		write(1, "0x", 2);
		ft_putnbrbase((long long)ptr, BASE_HEXA, char_written);
		*char_written += 2;
	}
}
