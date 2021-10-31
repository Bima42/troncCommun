#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PURCENT '%'
# define CHAR 'c'
# define INT 'i'
# define DOUBLE 'd'
# define UNSIGNED 'u'
# define HEXA 'x'
# define STRING 's'
# define POINTER 'p'
# include <stdio.h>
# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <string.h>

int     ft_printf(const char *str, ...);
void    ft_putnbr(int n);
void    ft_putnbr_unsigned(unsigned int n);
void    ft_putnbrbase(int nb, char *base);

#endif
