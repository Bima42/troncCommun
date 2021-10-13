/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:18:43 by tpauvret          #+#    #+#             */
/*   Updated: 2021/10/13 23:20:31 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ret;

	if (!(ft_strncmp(s, "", 1)))
		return (ft_strdup(""));
	if (!f)
		return (NULL);
	i = 0;
	ret = (char *)malloc(sizeof(char) * ft_strlen(s));
	if (ret == NULL)
		return (NULL);
	while (s[i])
	{
		ret[i] = (*f)(i, s[i]);
		i++;
	}
	return (ret);
}
