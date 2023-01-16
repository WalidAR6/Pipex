/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:44:11 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/16 18:05:50 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void    here_doc(int ac, char **av, char **envp)
{
    char    *line;
    t_heredoc   vars;
    int         tmp;
    int         fd[2];
    char        **cmd;
    char        **cmd1;
    char        *path;
    
    vars.outfile = ac - 1;
    vars.l_a = av[ac - 1];
    if (ac == 6 && !ft_strncmp(av[1], "here_doc", sizeof(av[1])))
    {
        check_last_arg(&vars);
        path = get_file_name(envp);
        vars.path = ft_split(path, ':');
        cmd = ft_split(av[3], ' ');
        cmd1 = ft_split(av[4], ' ');
        tmp = open("heredoc", O_RDWR | O_CREAT | O_TRUNC, 0644);
        if (!tmp)
            return ;
        while (1)
        {
            write(1, "> ", 2);
            line = get_next_line(0);
            if (line == NULL || !ft_strncmp(line, av[2], ft_strlen(av[2]) - 1))
                break;
            write(tmp,line, ft_strlen(line));
            free(line);
        }
        close(tmp);
        tmp = open("heredoc", O_RDONLY);
        pipe(fd);
        int id = fork();
        if (id == 0)
        {
            close(fd[0]);
            dup2(tmp, 0);
            dup2(fd[1], 1);
            close(fd[1]);
            close(tmp);
            execute_child(&vars, envp, cmd);
        }
        else
        {
            close(tmp);
            waitpid(id, 0, 0);
            int id2 = fork();
            if (id2 == 0)
            {
                close(fd[1]);
                dup2(fd[0], 0);
                dup2(vars.outfile, 1);
                close(fd[0]);
                execute_child(&vars, envp, cmd1);
            }
            else
                waitpid(id2, 0, 0);
        }
    }
    
}