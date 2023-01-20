/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_files_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:31:19 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/20 20:37:35 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

#define READ_END 0
#define WRITE_END 1

void multiple_pipes(int ac, char **av, char **envp)
{
    int fd[2];
    char *path;
    t_vars vars;
    int i;
    int res;
    int id;

    i = 2;
    vars.f_a = av[1];
    vars.l_a = av[ac - 1];
    if (ac > 1 && ft_strncmp(av[1], "here_doc", sizeof(av[1])))
    {
        check_first(&vars);
        check_last(&vars);
        path = get_file_name(envp);
        vars.path = ft_split(path, ':');
        dup2(vars.infile, 0);
        res = dup(0);
        while (i < ac - 1)
        {
            pipe(fd);
            id = fork();
            if (id == 0)
            {
                dup2(res, 0);
                dup2(fd[1], 1);
                close(res);
                close(fd[1]);
                close(fd[0]);
                if (i == ac - 2)
                    dup2(vars.outfile, 1);
                execute_first_cmd(&vars, envp, ft_split(av[i], ' '));
            }
            else
            {
                close(res);
                close(fd[1]);
                res = fd[0];
            }
            i++;
        }
        close(res);
    }
}


































        // pipe(fd);
        // dup2(vars.infile, 0);
        // int id = fork();
        // if(id == 0)
        // {
        //     close(fd[0]);
        //     close(fd[1]);
        //     execute_first_cmd(&vars, envp, ft_split(av[2], ' '));
        // }
        // else
        // {
        //     waitpid(id, 0, 0);
            
        //     close(fd[0]);
        //     close(fd[1]);
        // }
        // while (i < ac - 1)
        // {
        //     // pipe(fd);
        //     // if (i == 1)
        //     // {
        //     //     dup2(vars.infile, fd);
        //     //     i++;
        //     // }
        //     // else if (i == ac - 2)
        //     //     dup2(vars.outfile, 1);
        //     // id = fork();
        //     // if (id == 0)
        //     // {
        //     //     dup2(fd[0], 0);
        //     //     // dup2(fd[1], 1);
        //     //     execute_first_cmd(&vars, envp, ft_split(av[i], ' '));
        //     // }
        //     // if (i == 1)
        //     //     close(vars.infile);
        //     // else if (i == ac - 2)
        //     //     close(vars.outfile);
        //     // close(fd[1]);
        //     // close(fd[0]);
        //     // waitpid(id, 0, 0);
            
        // //     pipe(fd);
        // //     if (i == 1)
        // //     {
        // //         dup2(vars.infile, 0);
        // //         i++;
        // //     }
        // //     else if (i == ac - 2)
        // //     {
        // //         dup2(vars.outfile, 1);
        // //     }
        // //     id = fork();
        // //     if (id == 0)
        // //     {
        // //         close(fd[0]);
        // //         dup2(fd[1], 1);
        // //         close(fd[1]);
        // //         execute_first_cmd(&vars, envp, ft_split(av[i], ' '));
        // //     }
        // //     else
        // //     {
        // //         if (i == 0)
        // //             close(vars.infile);
        // //         else if (i == ac - 2)
        // //             close(vars.outfile);
        // //         dup2(fd[0], 0);
        // //         close(fd[1]);            
        // //     }
        // //     i++;
        // }
        // waitpid(-1 ,0 ,0);
        // waitpid(-1 ,0 ,0); 