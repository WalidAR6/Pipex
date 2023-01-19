/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:30:12 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/18 13:27:09 by waraissi         ###   ########.fr       */
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


typedef struct s_heredoc
{
    char    **envp;
    int outfile;
    char    **path;
    char    *l_a;
    char    *h_d;
    
}               t_heredoc;

typedef struct s_vars
{
    char    *f_a;
    char    *l_a;
    int     infile;
    int     outfile;
    char    **path;
}              t_vars;

void    here_doc(int ac, char **av, char **envp);
void    multuple_pipes(int ac, char **av, char **envp);
char    *get_name(t_heredoc *vars, char **cmd);
void    execute_child(t_heredoc *vars, char **cmd);
char    *get_file_name(char **envp);
char    **join_commands(t_heredoc *vars, char *arg);
int     get_paths_len(char **str);
void    check_last_arg(t_heredoc *vars);
void    multiple_pipes(int ac, char **av, char **envp);
void    check_first(t_vars *vars);
void    check_last(t_vars *vars);
void    execute_first_cmd(t_vars *vars, char **envp, char **cmd);
char    *get_name_multi(t_vars *vars, char **cmd);

#endif