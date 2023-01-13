/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:29:36 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/13 21:28:25 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

int main(int ac, char **av)
{
    t_params    vars;
    
    vars.f_a = av[1];
    vars.l_a = av[ac - 1];
    if (ac > 1)
    {
        check_first_arg(&vars);
        check_last_arg(&vars);
    }
    
    return 0;
}
