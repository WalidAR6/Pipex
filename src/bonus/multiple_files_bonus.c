/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_files_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:31:19 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/19 05:44:50 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

#define READ_END 0
#define WRITE_END 1

void multiple_pipes(int ac, char **av, char **envp)
{
    (void)envp;
    int fd[2];
    char *path;
    int id;
    int i;

    t_vars vars;
    i = 1;
    vars.f_a = av[1];
    vars.l_a = av[ac - 1];
    if (ac > 1)
    {
        check_first(&vars);
        check_last(&vars);
        path = get_file_name(envp);
        vars.path = ft_split(path, ':');
        while (i < ac - 1)
        {
            // pipe(fd);
            // if (i == 1)
            // {
            //     dup2(vars.infile, fd);
            //     i++;
            // }
            // else if (i == ac - 2)
            //     dup2(vars.outfile, 1);
            // id = fork();
            // if (id == 0)
            // {
            //     dup2(fd[0], 0);
            //     // dup2(fd[1], 1);
            //     execute_first_cmd(&vars, envp, ft_split(av[i], ' '));
            // }
            // if (i == 1)
            //     close(vars.infile);
            // else if (i == ac - 2)
            //     close(vars.outfile);
            // close(fd[1]);
            // close(fd[0]);
            // waitpid(id, 0, 0);
            
            pipe(fd);
            if (i == 1)
            {
                dup2(vars.infile, 0);
                i++;
            }
            else if (i == ac - 2)
            {
                dup2(vars.outfile, 1);
            }
            id = fork();
            if (id == 0)
            {
                close(fd[0]);
                dup2(fd[1], 1);
                close(fd[1]);
                execute_first_cmd(&vars, envp, ft_split(av[i], ' '));
            }
            else
            {
                if (i == 0)
                    close(vars.infile);
                else if (i == ac - 2)
                    close(vars.outfile);
                dup2(fd[0], 0);
                close(fd[1]);            
                waitpid(id ,0 ,0); 
            }
            i++;
        }
    }
}