/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:44:11 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/14 23:53:29 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void    here_doc(int ac, char **av, char **envp)
{
    char    *line;
    if (ac == 6 && !ft_strncmp(av[1], "here_doc", sizeof(av[1])))
    {
        while (1)
        {
            line = get_next_line(0);
        }
        
    }
    
}