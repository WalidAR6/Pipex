/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:00:42 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/12 18:47:15 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

int main(int ac, char **av, char **envp)
{
    t_params    vars;
    char        *path;
    char        **cmd1;
    char        **cmd2;

    vars.f_a = av[1];
    vars.l_a = av[ac - 1];
    if (ac == 5)
    {
        check_first_arg(&vars);
        check_last_arg(&vars);
        cmd1 = split_arg(av[2]);
        cmd2 = split_arg(av[3]);
        path = get_file_name(envp);
        vars.path = paths_file(path);
        exec_all_cmd(&vars, envp, cmd1, cmd2);
        
    }
    else
    {
        ft_printf(2, "Error check your args");
        exit(1);
    }
}
