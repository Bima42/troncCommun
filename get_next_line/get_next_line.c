/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:30:39 by tpauvret          #+#    #+#             */
/*   Updated: 2021/10/22 00:13:27 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_index_new_line(char *buf)
{
	int	index;

	index = 0;
	while (*buf)
	{
		if (*buf == '\n')
			return (index);
		index++;
		buf++;
	}
	if (*buf == '\n')
		return (index);
	return (0);
}

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*keep = NULL;
	char			*tmp;
	char			*final;
	unsigned int	newline;
	int				count;

	final = malloc(sizeof(char) * 1);
	*final = '\0';
	count = 1;
	while (count > 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		buf[count] = '\0';
		tmp = ft_strjoin(final, buf);
		free(final);
		final = tmp;
		newline = ft_index_new_line(final);
		if (newline != 0)
		{
			keep = ft_substr(tmp, (newline + 1), (ft_strlen(tmp) - newline));
			return (ft_substr(tmp, 0, newline));
		}
	}
	return (NULL);
}

int main()
{
	int	fd;
	char *ret;

	fd = open("test", O_RDONLY);
	ret = get_next_line(fd);
	printf("%s\n", ret);
	ret = get_next_line(fd);
	printf("%s\n", ret);
	ret = get_next_line(fd);
	printf("%s\n", ret);
	return (0);
}
