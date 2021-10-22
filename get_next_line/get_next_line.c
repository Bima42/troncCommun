/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:30:58 by tpauvret          #+#    #+#             */
/*   Updated: 2021/10/22 17:41:48 by tpauvret         ###   ########.fr       */
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
	unsigned int	newline;
	char			*ret;
	char			*tmp;
	int				count;

	count = 1;
	tmp = malloc(1);
	*tmp = '\0';
	while (count > 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		buf[count] = '\0';
		if (keep != NULL)
		{
			newline = ft_index_new_line(keep);
			if (newline)
				tmp = ft_substr(keep, 0, (newline + 1));
			else
				tmp = ft_strdup(keep);
			free(keep);
			keep = NULL;
		}
		newline = ft_index_new_line(buf);
		if (ft_strlen(buf))
		{
			keep = ft_substr(buf, (newline + 1), (ft_strlen(buf) - newline));
			ret = ft_strjoin(tmp, ft_substr(buf, 0, (newline + 1)));
			free(tmp);
			return (ret);
		}
		else if (ft_strlen(tmp))
			return (tmp);
	}
	free(tmp);
	return (NULL);
}

/*int main()
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
}*/
