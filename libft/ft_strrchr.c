/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:31:52 by tpauvret          #+#    #+#             */
/*   Updated: 2021/10/12 12:40:51 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = ft_strlen(s);
	if (count > 0)
	{
		while (s[count] != (char)c && count > 0)
			count--;
		if (s[count] == (char)c)
			return ((char *)(s + count));
	}
	return (NULL);
}

/*int	main()
{
	const char s[] = "qewwvfbpoiuytremmjmnhgbfvdcsf.;',.fwep";
	printf("result = %s\n", strrchr(s, 109));
	printf("result = %s\n", ft_strrchr(s, 109));
}*/
