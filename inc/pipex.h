/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:00:07 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/07 23:44:57 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_params
{
    int  infile;
    int  outfile;
    char *f_a;
    char *l_a;
    char **cmd1;
    char **cmd2;
    char *path;
}               t_params;

void    check_first_arg(t_params *vars);
void    check_last_arg(t_params *vars);
int     access_per(t_params *vars);
char    **split_arg(char *str);
char    *get_file_name(char **envp);

#endif