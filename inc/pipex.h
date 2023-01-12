/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:00:07 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/12 18:39:47 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
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
    char **path;
    char **path_cmd;
}               t_params;

void    check_first_arg(t_params *vars);
void    check_last_arg(t_params *vars);
char    **split_arg(char *str);
char    *get_file_name(char **envp);
char    **paths_file(char *str);
char    **join_commands(t_params *vars, char *cmd);
void    exec_all_cmd(t_params *vars, char **envp, char **cmd1, char **cmd2);
void    exec_cmd_2(t_params *vars, char **envp, char **cmd, int *fd);
char    *get_name(t_params *vars, char **cmd);
void    execute_cmd(t_params *vars, char **envp, char **cmd);

#endif