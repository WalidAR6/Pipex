/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:30:12 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/16 19:32:51 by waraissi         ###   ########.fr       */
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


void    here_doc(int ac, char **av, char **envp);
void    multuple_pipes(int ac, char **av, char **envp);
char    *get_name(t_heredoc *vars, char **cmd);
void    execute_child(t_heredoc *vars, char **cmd);
char    *get_file_name(char **envp);
char    **join_commands(t_heredoc *vars, char *arg);
int     get_paths_len(char **str);
void    check_last_arg(t_heredoc *vars);

#endif