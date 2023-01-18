/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_files_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:31:19 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/18 01:03:41 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

// void    execute_first_cmd(t_params *vars, char **envp)
// {
         
// }

void    multiple_pipes(int ac, char **av, char **envp)
{
    (void)envp;
    int fd[2];
    int id;

    t_params    vars;

    vars.f_a = av[1];
    vars.l_a = av[ac - 1];
    if (ac > 1)
    {
        check_first(&vars); 
        check_last(&vars);
        pipe(fd);
        id = fork();
        if (id == 0)
        {
            dup2(vars.infile, 0);
            close(fd[0]);
            dup2(fd[1], 1);
        }
        
    }   
}