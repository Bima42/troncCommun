/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:30:48 by tpauvret          #+#    #+#             */
/*   Updated: 2021/10/21 17:31:34 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

static char		*ft_strjoin(char const *s1, char const *s2);
static char		*ft_strcpy(char *dest, const char *src);
static char		*ft_substr(char const *s, unsigned int start, size_t len);
static char		*ft_strchr(const char *s, int c);
static size_t	ft_strlen(const char *str);

#endif
