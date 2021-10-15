/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 02:03:20 by tpauvret          #+#    #+#             */
/*   Updated: 2021/10/15 17:45:20 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_count_words(char const *s, char c)
{
	int		nb_words;
	int		flag;
	char	*cpy;

	nb_words = 0;
	cpy = (char *)s;
	while (*cpy == c)
		cpy++;
	if (*cpy != c && cpy)
		nb_words++;
	while (*cpy)
	{
		flag = 0;
		while (*cpy == c && *cpy)
		{
			flag = 1;
			cpy++;
		}
		if (flag && cpy)
			nb_words++;
		if (*cpy)
			cpy++;
	}
	return (--nb_words);
}

static int	*ft_start_words(char *s, char c, int nb_words)
{
	int	*size_words;
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	size_words = (int *)malloc(sizeof(int) * nb_words);
	if (!size_words)
		return (NULL);
	while (s[j] == c && s[j])
		j++;
	if (s[j] != c)
		size_words[i++] = j;
	while (s[j])
	{
		flag = 0;
		while (s[j] && s[j++] == c)
			flag = 1;
		if (flag)
			size_words[i++] = j;
	}
	return (size_words);
}

static char	*ft_fill_array(char *s, char c, int len)
{
	int	j;

	j = 0;
	while (*(s + len + j) && *(s + len + j) != c)
		j++;
	return (ft_substr(s, len, j));
}

/*static void	*ft_free(char **array, int i)
{
	while (i-- > 0)
		free(array[i]);
	free(array);
	return (NULL);
}*/

char	**ft_split(char const *s, char c)
{
	int		nb_words;
	int		i;
	char	**array;
	int		*start_words;

	i = 0;
	nb_words = ft_count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!array)
		return (NULL);
	start_words = ft_start_words((char *)s, c, nb_words);
	if (!start_words)
		return (NULL);
	while (array[i])
	{
		array[i] = ft_fill_array((char *)s, c, start_words[i]);
	//	if (array[i] == NULL)
	//		return (ft_free(array, i));
		i++;
	}
	array[nb_words] = NULL;
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
