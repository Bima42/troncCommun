/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:31:03 by tpauvret          #+#    #+#             */
/*   Updated: 2021/10/21 17:33:01 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	int		count;
	char	*res;

	res = (char *)s;
	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] == (char)c)
			return (res);
		count++;
		res++;
	}
	if (s[count] == (char)c)
		return (res);
	return (NULL);
}

static size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	count;

	count = 0;
	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
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

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ind;
	size_t	i;
	size_t	j;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	ind = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	j = 0;
	ret = (char *)malloc(sizeof(char) * (ind + 1));
	if (!ret)
		return (NULL);
	while (i < ind)
	{
		while (s1[++i] != '\0')
			ret[i] = s1[i];
		while (s2[j] != '\0')
		{
			ret[i] = s2[j++];
			i++;
		}
	}
	ret[i] = '\0';
	return (ret);
}
