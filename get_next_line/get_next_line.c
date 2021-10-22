/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:30:58 by tpauvret          #+#    #+#             */
/*   Updated: 2021/10/22 22:30:08 by tpauvret         ###   ########.fr       */
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
	return (-1);
}

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*keep;
	int				newline;
	char			*ret;
	char			*tmp;
	int				count;

	if (read(fd, 0, 0))
		return (NULL);
	if (!keep)
		keep = ft_substr("", 0, 1);
	count = 1;
	while (keep)
	{
		if (ft_index_new_line(keep) == -1)
		{
			count = read(fd, buf, BUFFER_SIZE);
			if (count < 0)
				return (NULL);
			buf[count] = '\0';
			tmp = ft_strjoin(keep, buf);
			free(keep);
			keep = tmp;
		}
		newline = ft_index_new_line(keep) + 1;
		if (newline > 0)
		{
			ret = ft_substr(keep, 0, newline);
			tmp = ft_substr(keep, newline, (ft_strlen(keep) - newline));
			free(keep);
			keep = tmp;
			return (ret);
		}
		else if (*keep && ! count)
		{
			ret = ft_substr(keep, 0, ft_strlen(keep));
			free(keep);
			keep = NULL;
			return(ret);
		}
		else if (! *keep && ! count)
		{
			free(keep);
			keep = NULL;
			break;
		}
	}
	return (NULL);
}
/*
int main()
{
	int	fd;
	char *ret;

	fd = open("test", O_RDONLY);
	ret = get_next_line(fd);
	printf("%s", ret);
	ret = get_next_line(fd);
	printf("%s", ret);
	ret = get_next_line(fd);
	printf("%s", ret);
	ret = get_next_line(fd);
	printf("%s", ret);
	ret = get_next_line(fd);
	printf("%s", ret);
	return (0);
}
*/
