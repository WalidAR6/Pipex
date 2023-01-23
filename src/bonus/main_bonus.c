/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:29:36 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/23 01:47:33 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

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

void	free_args(t_heredoc *vars, char **cmd1, char **cmd2, char **path)
{
	ft_free(cmd1);
	ft_free(cmd2);
	ft_free(path);
	ft_free(vars->path);
}

int	main(int ac, char **av, char **envp)
{
	here_doc(ac, av, envp);
	multiple_pipes(ac, av, envp);
	return (0);
}
