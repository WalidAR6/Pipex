/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:41:53 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/03 18:22:58 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_putstr(char *s, int *res)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		*res += 6;
	}
	else
	{
		while (s[i])
		{
			ft_putchar(s[i], res);
			i++;
		}
	}
}
