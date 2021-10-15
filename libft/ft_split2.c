/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:56:01 by tpauvret          #+#    #+#             */
/*   Updated: 2021/10/15 16:24:44 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

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

static int ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (++count);
}

static char	*ft_fill_array(char const *s, int *i, int len_w, char c)
{
	char	*str;
	int		count;
	int		j;

	count = *i - len_w;
	j = 0;
	str = (char *)malloc(sizeof(char) * (len_w + 1));
	if (str == NULL)
		return (NULL);
	while (count < *i)
	{
		str[j] = s[count];
		j++;
		count++;
	}
	str[j] = '\0';
	while (s[*i] == c)
		*i += 1;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		words;
	int		i;
	int		j;
	int		len_w;;

	while (*s == c)
		s++;
	if (*s == '\0')
		return ((char **)ft_strdup(""));
	words = ft_count_words(s, c);
	i = 0;
	j = 0;
	len_w = -1;
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (array == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		len_w++;
		if (s[i] == c)
		{
			array[j++] = ft_fill_array(s, &i, len_w, c);
			len_w = 0;
		}
		i++;
	}
	array[j++] = ft_fill_array(s, &i, ++len_w, c);
	return (array);
}

int	main()
{
	char const s[] = "split  ||this|for|me|||||!|";
	char c = '|';
	int i = 0;
	char	**split_rec = ft_split (s, c);

	while (i < 6)
	{
		printf("%s\n", split_rec[i]);
		i++;
	}
	return (0);
}
