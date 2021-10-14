/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:15:31 by tpauvret          #+#    #+#             */
/*   Updated: 2021/10/14 16:39:16 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0') && (s2[i] != '\0' && i < n))
		i++;
	if (i == n)
		return (0);
	else
		return ((int)s1[i] - (int)s2[i]);
}

/*int	main()
{
	int	x;
	int	y;
	size_t n;
	const char	test1[] = "saucisse";
	const char	test2[] = "sauCisse";
    const char	test3[] = "sau$isse";
	const char	test4[] = "";
	const char	test5[] = "*&^%";

	n = 4;
	x = strncmp(test1, test2, n);
	printf("Difference ? %d\n", x);
	x = strncmp(test1, test3, n);
	printf("Difference ? %d\n", x);
	x = strncmp(test1, test4, n);
	printf("Difference ? %d\n", x);
	x = strncmp(test1, test5, n);
	printf("Difference ? %d\n", x);

	y = ft_strncmp(test1, test2, n);
	printf("Difference ? %d\n", y);
	y = ft_strncmp(test1, test3, n);
	printf("Difference ? %d\n", y);
	y = ft_strncmp(test1, test4, n);
	printf("Difference ? %d\n", y);
	y = ft_strncmp(test1, test5, n);
	printf("Difference ? %d\n", y);
}*/
