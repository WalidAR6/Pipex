/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe_exe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:02:24 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/23 23:33:15 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

char	**join_commands_multi(t_vars *vars, char *arg)
{
	int		i;
	char	**cmd;

	i = 0;
	cmd = malloc((get_paths_len(vars->path) + 1) * sizeof(*cmd));
	if (!cmd)
		return (NULL);
	while (vars->path[i])
	{
		cmd[i] = ft_strjoin_sep(vars->path[i], arg, "/");
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}

char	*get_name_multi(t_vars *vars, char **cmd)
{
	char	**paths;
	int		i;

	i = 0;
	if (ft_strchr(cmd[0], '/'))
		paths = sep_first(cmd[0]);
	else
		paths = join_commands_multi(vars, cmd[0]);
	while (paths[i])
	{
		if (!access(paths[i], F_OK))
			break ;
		i++;
	}
	return (paths[i]);
}

void	execute_first_cmd(t_vars *vars, char **envp, char **cmd)
{
	char	*file_name;

	file_name = get_name_multi(vars, cmd);
	if (execve(file_name, cmd, envp) == -1)
		ft_printf(2, "%s: command not found\n", cmd[0]);
}
