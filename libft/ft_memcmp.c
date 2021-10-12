/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:57:04 by tpauvret          #+#    #+#             */
/*   Updated: 2021/10/11 19:12:28 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*sc1;
	unsigned char	*sc2;

	sc1 = (unsigned char *)s1;
	sc2 = (unsigned char *)s2;
	count = 0;
	while (count < n)
	{
		if (sc1[count] > sc2[count])
			return (1);
		else if (sc1[count] < sc2[count])
			return (-1);
		count++;
	}
	return (0);
}

/*int main()
{
        char s1[] = "salutest";
        char s2[] = "tamalemusty";
        char s3[] = "salalemusty";
        char s4[] = "salutemusty";
        char s5[] = "";
        char s6[] = " ";

        printf("%d\n", memcmp(s1, s2, 5));
        printf("%d\n", memcmp(s1, s3, 5));
        printf("%d\n", memcmp(s1, s4, 5));
        printf("%d\n", memcmp(s1, s5, 5));
        printf("%d\n", memcmp(s1, s6, 5));

        printf("------------------------\n");
		printf("%d\n", ft_memcmp(s1, s2, 5));
        printf("%d\n", ft_memcmp(s1, s3, 5));
        printf("%d\n", ft_memcmp(s1, s4, 5));
        printf("%d\n", ft_memcmp(s1, s5, 5));
        printf("%d\n", ft_memcmp(s1, s6, 5));
}*/
