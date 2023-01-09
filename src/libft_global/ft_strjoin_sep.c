/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:39:16 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/09 14:18:38 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char    *ft_strjoin_sep(char *s1, char *s2, char *sep)
{
    size_t	i;
	size_t	j;
	size_t	x;
	char	*p;

	i = 0;
	j = 0;
    x = 0;
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(sep) + 1);
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
    while (sep[x])
    {
        p[x + i] = sep[x];
        x++;
    }
	while (s2[j])
	{
		p[i + x + j] = s2[j];
		j++;
	}
	p[i + x + j] = 0;
	return (free(s1), s1 = NULL, p);
}