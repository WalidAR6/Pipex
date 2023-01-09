/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:00:42 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/09 21:56:36 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

int main(int ac, char **av, char **envp)
{
    t_params    vars;
    char        *path;
    
    vars.f_a = av[1];
    vars.l_a = av[ac - 1];
    if (ac == 5)
    {
        check_first_arg(&vars);
        check_last_arg(&vars);
        vars.cmd1 = split_arg(av[2]);
        vars.cmd2 = split_arg(av[3]);
        path = get_file_name(envp);
        vars.path = paths_file(path);
        vars.path_cmd = join_commands(&vars, envp);
    }
}
