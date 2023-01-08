/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:24:28 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/08 01:49:28 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void    join_commands(t_params *vars)
{
    int i;
    char *cmd;
    
    i = 0;
    while (vars->path[i])
    {
        cmd = NULL;
        cmd = ft_strjoin(vars->path[i], vars->cmd1[0]);
        i++;
    }   
}