/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:23:01 by tpauvret          #+#    #+#             */
/*   Updated: 2021/11/04 13:34:15 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	detection_type(va_list args, const char *str, int count);

static int	detection_type(va_list args, const char *str, int count)
{
	int	char_written;

	char_written = 0;
	if (str[count] == PURCENT)
		ft_putchar_count(PURCENT, &char_written);
	else if (str[count] == CHAR)
		ft_putchar_count(va_arg(args, int), &char_written);
	else if (str[count] == STRING)
		ft_putstr(va_arg(args, char *), &char_written);
	else if (str[count] == INT)
		ft_putnbr(va_arg(args, int), &char_written);
	else if (str[count] == DECIMAL)
		ft_putnbr(va_arg(args, int), &char_written);
	else if (str[count] == UNSIGNED)
		ft_putnbr_unsigned(va_arg(args, unsigned int), &char_written);
	else if (str[count] == HEXA)
		ft_putnbrbase(va_arg(args, unsigned int), BASE_HEXA, &char_written);
	else if (str[count] == HEXA_UP)
		ft_putnbrbase(va_arg(args, unsigned int), BASE_HEXA_MAJ, &char_written);
	else if (str[count] == POINTER)
		ft_get_address_ptr(va_arg(args, void *), &char_written);
	return (char_written);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		count_ret;

	va_start(args, str);
	count = 0;
	count_ret = ft_count_ret(str);
	while (str[count] != '\0')
	{
		if (str[count] == '%')
			count_ret += detection_type(args, str, ++count);
		else
			ft_putchar(str[count]);
		count++;
	}
	va_end(args);
	return (count_ret);
}
