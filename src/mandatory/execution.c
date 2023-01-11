/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:41:05 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/11 22:43:06 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void    exec_cmd_2(t_params *vars, char **envp, char **cmd, int *fd)
{
    int id;
    
    id = fork();
    if (id == 0)
    {
        close(fd[1]);
        dup2(fd[0], 0);
        dup2(vars->outfile, 1);
        execute_cmd(vars, envp, cmd);
    }
    wait(NULL);
    close(fd[0]);
}

void    exec_all_cmd(t_params *vars, char **envp, char **cmd1, char **cmd2)
{
    int fds[2];
    int id;
    (void)cmd2;
    
    pipe(fds);
    id = fork();
    if (id == 0)
    {
        close(fds[0]);
        dup2(vars->infile, 0);
        dup2(fds[1], 1);
        execute_cmd(vars, envp, cmd1);
    }
    wait(NULL);
    close(fds[1]);
    exec_cmd_2(vars, envp, cmd2, fds);
}
