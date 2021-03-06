/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:27:27 by tpauvret          #+#    #+#             */
/*   Updated: 2021/11/04 13:34:17 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PURCENT '%'
# define CHAR 'c'
# define INT 'i'
# define DECIMAL 'd'
# define UNSIGNED 'u'
# define HEXA 'x'
# define HEXA_UP 'X'
# define STRING 's'
# define POINTER 'p'
# define BASE_HEXA "0123456789abcdef"
# define BASE_HEXA_MAJ "0123456789ABCDEF"
# include <stdio.h>
# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <string.h>

int		ft_printf(const char *str, ...);
int		ft_nbrlen_hexa(unsigned long nb);
void	ft_putnbr(int n, int *char_written);
void	ft_putnbr_unsigned(unsigned int n, int *char_written);
void	ft_putnbrbase(unsigned long nb, char *base, int *char_written);
void	ft_putchar_count(char c, int *char_written);
void	ft_get_address_ptr(void *ptr, int *char_written);
int		ft_count_ret(const char *str);
void	ft_putstr(const char *str, int *count);

#endif
