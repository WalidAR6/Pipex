/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:54:56 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/22 00:01:44 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	check_first_arg(t_params *vars)
{
	vars->infile = open(vars->f_a, O_RDONLY);
	if (vars->infile == -1)
	{
		ft_printf(2, "%s: No such file or directory\n", vars->f_a);
		exit(1);
	}
}

void	check_last_arg(t_params *vars)
{
	vars->outfile = open(vars->l_a, O_WRONLY | O_CREAT | O_TRUNC, 777);
	if (vars->outfile == -1)
	{
		ft_printf(2, "Error");
		exit(1);
	}
}
