/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:52:55 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/07 23:45:04 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

char    *get_file_name(char **envp)
{
    int i;

    i = 0;
    while (envp[i])
    {
        if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
            return (envp[i]);
        i++;
    }
    return (NULL);
}