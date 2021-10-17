/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 02:03:20 by tpauvret          #+#    #+#             */
/*   Updated: 2021/10/16 23:30:47 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_count_words(char const *s, char c);
static int	*ft_start_words(char *s, char c, int nb_words);
static char	*ft_fill_array(char *s, char c, int len);
static void	*ft_free(char **array, int i);

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (s[i] == c)
		words--;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			words++;
		i++;
	}
	return (words + 1);
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
	if (size_words == NULL)
		return (NULL);
	if (s[j] != c)
		size_words[i++] = j++;
	while (s[j])
	{
		flag = 0;
		if (s[j] != c && s[j - 1] == c)
			flag = 1;
		if (s[j] && flag)
			size_words[i++] = j;
		j++;
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

static void	*ft_free(char **array, int i)
{
	while (i--)
		free(array[i]);
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		nb_words;
	int		i;
	char	**array;
	int		*start_words;

	if (!s)
		return (NULL);
	i = 0;
	nb_words = ft_count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (array == NULL)
		return (NULL);
	start_words = ft_start_words((char *)s, c, nb_words);
	if (!start_words)
		return (NULL);
	while (i < nb_words)
	{
		array[i] = ft_fill_array((char *)s, c, start_words[i]);
		if (array[i] == NULL)
			return (ft_free(array, i));
		i++;
	}
	array[nb_words] = NULL;
	return (array);
}

/*int	main()
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
}*/
