/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:24:28 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/09 22:28:42 by waraissi         ###   ########.fr       */
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

char    **join_commands(t_params *vars, char **envp)
{
    int i;
    char **cmd;
    int fd;

    i = 0;
    fd = dup(0);
    dup2(vars->infile, 0);
    cmd = malloc((get_paths_len(vars->path) + 1) * sizeof(*cmd));
    if(!cmd)
        return (NULL);
    while (vars->path[i])
    {
        cmd[i] = ft_strjoin_sep(vars->path[i], vars->cmd1[0], "/");
        if (!access(cmd[i], F_OK))
            execute_cmd(vars, cmd[i], envp);
        i++;
    }
    printf("file not found\n");
    cmd[i] = NULL;
    return (cmd);
}