/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:42:06 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/03 18:55:18 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	ft_putnbr(int n, int *res)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", res);
	else if (n < 0)
	{
		n = -n;
		ft_putchar('-', res);
		ft_putnbr(n, res);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + 48, res);
		else
		{
			ft_putnbr(n / 10, res);
			ft_putnbr(n % 10, res);
		}
	}
}
