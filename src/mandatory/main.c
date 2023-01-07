/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:00:42 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/07 01:00:12 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

int main(int ac, char **av)
{
    t_params    vars;
    
    vars.f_a = av[1];
    vars.l_a = av[ac - 1];
    if (ac == 5)
    {
        check_first_arg(vars.f_a);
        ft_printf(1,"%s %s\n",vars.f_a,vars.l_a);
    }
    
}
