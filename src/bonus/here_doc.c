/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:44:11 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/16 02:22:06 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void    check_last_arg(t_heredoc *vars)
{
    vars->outfile = open(vars->l_a, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (vars->outfile == -1)
    {
        ft_printf(2,"Error");
    }
}

char    *get_file_name(char **envp)
{
    int i;
    char **splited_line;

    i = 0;
    while (envp[i])
    {
        if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
        {
            splited_line = ft_split(envp[i], '=');
            return (splited_line[1]);
        }
        i++;
    }
    return (ft_printf(2, "commands not found\n"), NULL);
}

int     get_paths_len(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

char    **join_commands(t_heredoc *vars, char *arg)
{
    int i;
    char **cmd;

    i = 0;
    cmd = malloc((get_paths_len(vars->path) + 1) * sizeof(*cmd));
    if(!cmd)
        return (NULL);
    while (vars->path[i])
    {
        cmd[i] = ft_strjoin_sep(vars->path[i], arg, "/");
        i++;
    }
    cmd[i] = NULL;
    return (cmd);
}

char    *get_name(t_heredoc *vars, char **cmd)
{
    char **paths;
    int i;

    i = 0;
    paths = join_commands(vars, cmd[0]);
    while (paths[i])
    {
        if (!access(paths[i], F_OK))
            break;
        i++;
    }
    return (paths[i]);
}

void    execute_child(t_heredoc *vars, char **envp, char **cmd)
{
    char    *file_name;

    file_name = get_name(vars, cmd);
    if(execve(file_name, cmd, envp) == -1)
        ft_printf(2, "%s: command not found\n", cmd[0]);
}

void    here_doc(int ac, char **av, char **envp)
{
    char    *line;
    t_heredoc   vars;
    int         tmp;
    // int         fd[2];
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
        // pipe(fd);
        int id = fork();
        if (id == 0)
        {
            dup2(tmp, 0);
            // dup2(vars.outfile, 1);
            // dup2(fd[1], 1);
            execute_child(&vars, envp, cmd);
        }
        else
        {
            close(tmp);
            waitpid(id, 0, 0);
        }
    }
    
}