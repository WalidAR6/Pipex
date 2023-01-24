/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:43:26 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/24 00:49:09 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

char	**sep_first(char *arg)
{
	char	**cmd;

	cmd = malloc(2 * sizeof(char *));
	if (!cmd)
		return (NULL);
	cmd[0] = ft_strdup(arg);
	cmd[1] = NULL;
	return (cmd);
}

char	*get_name(t_params *vars, char **cmd)
{
	char	**paths;
	int		i;
	char	*p;

	i = 0;
	if (ft_strchr(cmd[0], '/'))
		paths = sep_first(cmd[0]);
	else
		paths = join_commands(vars, cmd[0]);
	while (paths[i])
	{
		if (!access(paths[i], X_OK | F_OK))
			break ;
		i++;
	}
	if (paths[i] == NULL)
		return (ft_free(paths), NULL);
	p = ft_strdup(paths[i]);
	return (ft_free(paths), p);
}

void	execute_cmd(t_params *vars, char **envp, char **cmd)
{
	char	*file_name;

	file_name = get_name(vars, cmd);
	if (file_name == NULL)
	{
		ft_printf(2, "%s: command not found\n", cmd[0]);
		exit(1);
	}
	execve(file_name, cmd, envp);
	ft_printf(2, "%s: command not found\n", cmd[0]);
	free(file_name);
	exit(1);
}
