#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PURCENT '%'
# define CHAR 'c'
# define INT 'i'
# define STRING 's'
# define POINTER 'p'
# include <stdio.h>
# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <string.h>

int     ft_printf(const char *str, ...);
void    ft_putnbrbase(int nb, char *base);

#endif
