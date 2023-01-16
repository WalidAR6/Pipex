/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:44:11 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/16 18:53:35 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void    execution_sec(t_heredoc *vars, int *fd, char **cmd1)
{
    int id = fork();
    if (id == 0)
    {
        close(fd[1]);
        dup2(fd[0], 0);
        close(fd[0]);
        dup2(vars->outfile, 1);
        execute_child(vars, cmd1);
    }
    else
        waitpid(id, 0, 0);
}

void    execution(t_heredoc *vars, int tmp, char **cmd, char **cmd1)
{
    int fd[2];
    int id;
    
    pipe(fd);
    id = fork();
    if (id == 0)
    {
        close(fd[0]);
        dup2(tmp, 0);
        close(tmp);
        dup2(fd[1], 1);
        close(fd[1]);
        execute_child(vars, cmd);
    }
    else
    {
        waitpid(id, 0, 0);
        execution_sec(vars, fd, cmd1);
        close(tmp);
        close(fd[0]);
        close(fd[1]);
    }
        
}

void    execute_heredoc(t_heredoc *vars, char **cmd, char **cmd1)
{
    int tmp;
    char *line;

    tmp = open("heredoc", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (!tmp)
        return ;
    while (1)
    {
        write(1, "> ", 2);
        line = get_next_line(0);
        if (line == NULL || !ft_strncmp(line, vars->h_d, ft_strlen(vars->h_d) - 1))
            break;
        write(tmp,line, ft_strlen(line));
        free(line);
    }
    close(tmp);
    tmp = open("heredoc", O_RDONLY);
    execution(vars, tmp, cmd, cmd1);
}

void    here_doc(int ac, char **av, char **envp)
{
    t_heredoc   vars;
    char        **cmd;
    char        **cmd1;
    char        *path;

    vars.outfile = ac - 1;
    vars.l_a = av[ac - 1];
    vars.h_d = av[2];
    vars.envp = envp;
    if (ac == 6 && !ft_strncmp(av[1], "here_doc", sizeof(av[1])))
    {
        check_last_arg(&vars);
        path = get_file_name(envp);
        vars.path = ft_split(path, ':');
        cmd = ft_split(av[3], ' ');
        cmd1 = ft_split(av[4], ' ');
        execute_heredoc(&vars, cmd, cmd1);
    }
}