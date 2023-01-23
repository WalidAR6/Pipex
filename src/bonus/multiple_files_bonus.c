/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_files_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:31:19 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/23 01:52:46 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void	helper(t_vars *vars, int ac, char **av, char **envp)
{
	vars->ac = ac;
	vars->av = av;
	vars->envp = envp;
	vars->f_a = av[1];
	vars->l_a = av[ac - 1];
	check_first(vars);
	check_last(vars);
}

void	close_fds(int fd0, int fd1, int res, int n)
{
	if (n == 1)
	{
		if (close(res) == -1 || close(fd1) == -1 || close(fd0) == -1)
			exit(1);
	}
	else if (n == 2)
	{
		if (close(res) == -1 || close(fd1) == -1)
			exit(1);
	}
}

void	execute_multi_pipe(t_vars *vars, int i)
{
	int	id;

	if (pipe(vars->fd) == -1)
		exit(1);
	id = fork();
	if (id == -1)
		exit(1);
	if (id == 0)
	{
		if (dup2(vars->res, 0) == -1 || dup2(vars->fd[1], 1) == -1)
			exit(1);
		close_fds(vars->fd[0], vars->fd[1], vars->res, 1);
		if (i == vars->ac - 2)
			if (dup2(vars->outfile, 1) == -1)
				exit(1);
		execute_first_cmd(vars, vars->envp, ft_split(vars->av[i], ' '));
	}
	else
	{
		waitpid(id, 0, 0);
		close_fds(vars->fd[0], vars->fd[1], vars->res, 2);
		vars->res = vars->fd[0];
	}
}

void	multiple_pipes(int ac, char **av, char **envp)
{
	t_vars	vars;
	int		i;
	char	**path;

	i = 2;
	if (ac > 1 && ft_strncmp(av[1], "here_doc", sizeof(av[1])))
	{
		path = get_file_name(envp);
		vars.path = ft_split(path[1], ':');
		helper(&vars, ac, av, envp);
		dup2(vars.infile, 0);
		vars.res = dup(0);
		while (i < ac - 1)
		{
			execute_multi_pipe(&vars, i);
			i++;
		}
		if (close(vars.res) == -1)
			exit(1);
		ft_free(path);
		ft_free(vars.path);
	}
}
