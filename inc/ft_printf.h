/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:43:39 by waraissi          #+#    #+#             */
/*   Updated: 2022/11/10 18:20:59 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdarg.h>

void	ft_putchar(char c, int *res);
void	ft_putstr(char *s, int *res);
void	ft_putnbr(int n, int *res);
void	ft_putnbr_unsigned(unsigned int nbr, int *res);
void	ft_putnbr_base(unsigned long long nbr, int *res);
void	ft_putnbr_base_lower(unsigned int nbr, int *res);
void	ft_putnbr_base_upper(unsigned int nbr, int *res);
int		ft_printf(const char *str, ...);

#endif