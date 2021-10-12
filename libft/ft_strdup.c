/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:06:41 by tpauvret          #+#    #+#             */
/*   Updated: 2021/10/12 12:08:06 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size_src;
	int		c;
	char	*string;
	char	*ret;

	size_src = ft_strlen((char *)s1);
	string = (char *)s1;
	ret = malloc(size_src * sizeof(char));
	if (ret == NULL)
		return (NULL);
	c = 0;
	while (c != size_src)
	{
		ret[c] = string[c];
		c++;
	}
	ret[c] = '\0';
	return (ret);
}
