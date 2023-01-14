/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:30:12 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/14 19:55:54 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_main
{
    int ac;
    char **av;
    char **envp;
}               t_main;

typedef struct s_params
{
    t_main *main;
}               t_params;

void    here_doc(int ac, char **av, char **envp);

#endif