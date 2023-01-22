/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:00:42 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/22 23:34:44 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	ft_free(char **p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
}

void	free_args(t_params *vars, char **cmd1, char **cmd2, char **path)
{
	ft_free(cmd1);
	ft_free(cmd2);
	ft_free(path);
	ft_free(vars->path);
}

int	main(int ac, char **av, char **envp)
{
	t_params	vars;
	char		**path;
	char		**cmd1;
	char		**cmd2;

	vars.f_a = av[1];
	vars.l_a = av[ac - 1];
	if (ac == 5)
	{
		check_first_arg(&vars);
		check_last_arg(&vars);
		cmd1 = ft_split(av[2], ' ');
		cmd2 = ft_split(av[3], ' ');
		path = get_file_name(envp);
		vars.path = ft_split(path[1], ':');
		exec_all_cmd(&vars, envp, cmd1, cmd2);
		free_args(&vars, cmd1, cmd2, path);
	}
	else
	{
		ft_printf(2, "Error check your args");
		exit(1);
	}
}
