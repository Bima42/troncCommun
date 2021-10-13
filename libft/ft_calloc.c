/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:08:51 by tpauvret          #+#    #+#             */
/*   Updated: 2021/10/13 14:33:00 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	int		i;

	i = 0;
	ret = malloc(count * size);
	if (ret == NULL)
		return (NULL);
	while (size--)
	{
		((char *)ret)[i] = '\0';
		i++;
	}
	return ((void *)ret);
}

/*int	main()
{
	ft_calloc(5, 4);
	return (0);
}*/
