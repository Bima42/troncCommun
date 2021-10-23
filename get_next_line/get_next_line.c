/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:30:39 by tpauvret          #+#    #+#             */
/*   Updated: 2021/10/23 19:51:56 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	index_new_line(char *buf);
static void	clear(char **keep);
static char	*refactor(char **keep, char **tmp, int count);
static char	*refactor(char **keep, char **tmp, int count);

static int	index_new_line(char *buf)
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

static void	clear(char **keep)
{
	free(*keep);
	*keep = NULL;
}

static char	*refactor(char **keep, char **tmp, int count)
{
	int		newline;
	char	*ret;

	newline = index_new_line(*keep) + 1;
	if (newline > 0)
	{
		ret = ft_substr(*keep, 0, newline);
		if (!ret)
			return (NULL);
		*tmp = ft_substr(*keep, newline, (ft_strlen(*keep) - newline));
		if (!tmp)
			return (NULL);
		free(*keep);
		*keep = *tmp;
		return (ret);
	}
	else if (**keep && !count)
	{
		ret = ft_substr(*keep, 0, ft_strlen(*keep));
		if (!ret)
			return (NULL);
		clear(keep);
		return (ret);
	}
	return (NULL);
}

static char	*rerefactor(char **keep, char **tmp, int *count, int fd)
{
	char	buf[BUFFER_SIZE + 1];

	*count = read(fd, buf, BUFFER_SIZE);
	if (*count < 0)
		return (NULL);
	buf[*count] = '\0';
	*tmp = ft_strjoin(*keep, buf);
	if (!tmp)
		return (NULL);
	free(*keep);
	*keep = *tmp;
	return ("mamalemusty");
}

char	*get_next_line(int fd)
{
	char			*buf;
	static char		*keep;
	char			*tmp;
	int				count;

	if (read(fd, 0, 0))
		return (NULL);
	if (!keep)
		keep = ft_substr("", 0, 1);
	count = 0;
	while (keep)
	{
		if (index_new_line(keep) == -1)
		{
			buf = rerefactor(&keep, &tmp, &count, fd);
			if (buf == NULL)
				return (NULL);
		}
		if (index_new_line(keep) + 1 > 0 || (*keep && !count))
			return (refactor(&keep, &tmp, count));
		if (!*keep && !count)
			clear(&keep);
	}
	return (NULL);
}
