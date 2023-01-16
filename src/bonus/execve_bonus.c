/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:59:55 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/16 18:40:43 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

char    *get_name(t_heredoc *vars, char **cmd)
{
    char **paths;
    int i;

    i = 0;
    paths = join_commands(vars, cmd[0]);
    while (paths[i])
    {
        if (!access(paths[i], F_OK))
            break;
        i++;
    }
    return (paths[i]);
}

void    execute_child(t_heredoc *vars, char **cmd)
{
    char    *file_name;

    file_name = get_name(vars, cmd);
    if(execve(file_name, cmd, vars->envp) == -1)
        ft_printf(2, "%s: command not found\n", cmd[0]);
}
