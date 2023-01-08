/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:52:55 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/07 23:55:35 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

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
    return (NULL);
}

char    **paths_file(char *str)
{
    char **paths;

    paths = ft_split(str, ':');
    return (paths);
}