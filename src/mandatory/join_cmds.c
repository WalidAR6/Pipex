/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:24:28 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/11 01:01:23 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

int     get_paths_len(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

void    execute_cmd(t_params *vars, char *cmd, char **envp)
{
    execve(cmd, vars->cmd1, envp);
}

void    execute_cmd_(t_params *vars, char *cmd, char **envp)
{
    execve(cmd, vars->cmd2, envp);
}

void    exec_cmd_2(t_params *vars, int *fds, char **envp)
{
    char **cmd2;
    int i;
    int fd;


    i = 0;
    cmd2 = malloc((get_paths_len(vars->path) + 1) * sizeof(*cmd2));
    while (vars->path[i])
    {
        cmd2[i] = ft_strjoin_sep(vars->path[i], vars->cmd2[0], "/");
        if (!access(cmd2[i], F_OK))
        {
            ft_printf(2, "%s\n",cmd2[i]);
            ft_printf(2, "%s\n",cmd2[i + 1]);
            fd = fork();
            if (fd == 0)
            {
                close(fds[1]);
                dup2(fds[0], 0);
                dup2(vars->outfile, 1);
                execve(cmd2[i], vars->cmd2, envp);
            }
            wait(NULL);
        }
        i++;
    }
}

char    **join_commands(t_params *vars, char **envp)
{
    int i;
    char **cmd1;
    int fds[2];
    int id;

    i = 0;
    cmd1 = malloc((get_paths_len(vars->path) + 1) * sizeof(*cmd1));
    if(!cmd1)
        return (NULL);
    pipe(fds);
    while (vars->path[i])
    {
        cmd1[i] = ft_strjoin_sep(vars->path[i], vars->cmd1[0], "/");
        if (!access(cmd1[i], F_OK))
        {
            id = fork();
            if (id == 0)
            {
                dup2(vars->infile, 0);
                close(fds[0]);
                dup2(fds[1], 1);
                execute_cmd(vars, cmd1[i], envp);  
            }
            wait(NULL);
            close(fds[1]);
            exec_cmd_2(vars, fds, envp);
            close(fds[0]);
        }
        i++;
    }
    cmd1[i] = NULL;
    return (cmd1);
}