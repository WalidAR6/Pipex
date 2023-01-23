/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:43:26 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/23 15:53:45 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

char	*get_name(t_params *vars, char **cmd)
{
	char	**paths;
	int		i;
	char	*p;

	i = 0;
	paths = join_commands(vars, cmd[0]);
	while (paths[i])
	{
		if (!access(paths[i], F_OK))
			break ;
		i++;
	}
	p = ft_strdup(paths[i]);
	return (ft_free(paths), p);
}

void	execute_cmd(t_params *vars, char **envp, char **cmd)
{
	char	*file_name;

	file_name = get_name(vars, cmd);
	if (execve(file_name, cmd, envp) == -1)
		ft_printf(2, "%s: command not found\n", cmd[0]);
	free(file_name);
}
