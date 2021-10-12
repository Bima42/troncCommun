/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:56:28 by tpauvret          #+#    #+#             */
/*   Updated: 2021/10/12 12:29:17 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((unsigned char)c >= 32 && (unsigned char)c <= 126)
		return (1);
	return (0);
}

/*int main()
{
	printf("alnum ? %d\n", isprint('a'));
	printf("alnum ? %d\n", isprint('g'));
	printf("alnum ? %d\n", isprint('C'));
	printf("alnum ? %d\n", isprint('5'));
	printf("alnum ? %d\n", isprint('['));
	printf("alnum ? %d\n", isprint('	'));
	printf("alnum ? %d\n", ft_isprint('a'));
	printf("alnum ? %d\n", ft_isprint('g'));
	printf("alnum ? %d\n", ft_isprint('C'));
	printf("alnum ? %d\n", ft_isprint('5'));
	printf("alnum ? %d\n", ft_isprint('['));
	printf("alnum ? %d\n", isprint('	'));
}*/
