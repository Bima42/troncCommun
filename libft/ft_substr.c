/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:47:14 by tpauvret          #+#    #+#             */
/*   Updated: 2021/10/12 22:21:53 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	count;

	count = 0;
	if (!s)
		return (NULL);
	if ((int)start > ft_strlen(s))
		return (ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	while (count < len)
	{
		ret[count] = s[start + count];
		count++;
	}
	ret[count] = '\0';
	return (ret);
}
